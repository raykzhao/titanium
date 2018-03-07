/* ****************************** *
 * Titanium_CCA_hi                *
 * Implemented by Raymond K. ZHAO *
 *                                *
 * Packing/Unpacking              *
 * ****************************** */

#include "pack.h"
#include "param.h"
#include "littleendian.h"
#include <stdint.h>
#include <x86intrin.h>

#define Q_BITS_PACK 5 /* pack/unpack each 5 bytes */

static const __m256i V_Q_Q_Q_Q = {Q, Q, Q, Q};
static const __m256i V_1_1_1_1 = {1, 1, 1, 1};

static inline uint32_t con_sub(uint32_t x) /* conditional subtraction of q */
{
	return x - (1 ^ ((x - Q) >> 31)) * Q;
}

/* convert a polynomial to a binary string */
void poly_encode(unsigned char *b, const uint64_t *p, uint32_t len)
{
	uint32_t i;
	unsigned char *bb;
	uint64_t pp[4];
	__m256i u, t;
	
	/* pack 4 20-bit coordinates to 10 bytes */
	for (i = 0; i < len; i += 4)
	{
		/* make sure each coordinate is smaller than Q */
		u = _mm256_loadu_si256((__m256i *)(p + i));
		t = _mm256_sub_epi64(u, V_Q_Q_Q_Q);
		t = _mm256_srli_epi64(t, 63);
		t = _mm256_xor_si256(t, V_1_1_1_1);
		t = _mm256_mul_epu32(t, V_Q_Q_Q_Q);
		t = _mm256_sub_epi64(u, t);
		_mm256_storeu_si256((__m256i *)pp, t);

		bb = b + (i / 2) * Q_BITS_PACK;
		bb[0] = pp[0];
		bb[1] = pp[0] >> 8;
		bb[2] = (pp[0] >> 16) | ((pp[1] & 0x0f) << 4);
		bb[3] = pp[1] >> 4;
		bb[4] = pp[1] >> 12;
		bb[5] = pp[2];
		bb[6] = pp[2] >> 8;
		bb[7] = (pp[2] >> 16) | ((pp[3] & 0x0f) << 4);
		bb[8] = pp[3] >> 4;
		bb[9] = pp[3] >> 12;
	}
}

/* convert a binary string to a polynomial */
void poly_decode(uint64_t *p, const unsigned char *b, uint32_t len)
{
	uint32_t i;
	unsigned char *bb;
	
	/* unpack 5 bytes to 2 20-bit coordinates */
	for (i = 0; i < len; i += 2)
	{
		bb = b + (i / 2) * Q_BITS_PACK;

		p[i] = ((uint64_t)bb[0]) | (((uint64_t)bb[1]) << 8) | ((((uint64_t)bb[2]) & 0x0f) << 16);
		p[i + 1] = (((uint64_t)bb[2]) >> 4) | (((uint64_t)bb[3]) << 4) | (((uint64_t)bb[4]) << 12);
	}
}

/* convert a polynomial to a binary string (with compression) */
void poly_encode_c2(unsigned char *b, const uint64_t *p, uint32_t len)
{
	uint32_t i;

	for (i = 0; i < len; i++)
	{
		/* each coordinate will become 1 bytes after compression */
		STORE_C2(b + i * C2_COMPRESSION_BYTE, (con_sub(p[i])) >> C2_COMPRESSION_BITS);
	}
}

/* convert a binary string to a polynomial (with compression) */
void poly_decode_c2(uint64_t *p, const unsigned char *b, uint32_t len)
{
	uint32_t i;
	
	for (i = 0; i < len; i++)
	{
		/* shift the compressed coordinates back */
		p[i] = ((uint64_t)(LOAD_C2(b + i * C2_COMPRESSION_BYTE))) << C2_COMPRESSION_BITS;
	}
}


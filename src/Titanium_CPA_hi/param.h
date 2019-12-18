/* ****************************** *
 * Titanium_CPA_hi                *
 * Implemented by Raymond K. ZHAO *
 *                                *
 * Parameters                     *
 * ****************************** */
 
#ifndef PARAM_H
#define PARAM_H

#define CRYPTO_RANDOMBYTES 32

#define Q 737281
#define Q2 (Q << 1) /* Q*2 */
#define Q_BITS 20 /* 20 bits for a number in Z_q */

#define ZQ_BYTES 3 /* 3 random bytes to sample a number in Z_q */
#define LOAD_ZQ load_24

/* the actual number of random coordinates generated by sampler_zq */
#define ZQ_BYTPCS 2857
#define ZQ_BYTPCA 1760

#define N 1536

#define K1 767

#define D 256
#define D_BYTES 32 /* 256 --> 32 bytes */

/* function names of the NTTs */
#define NTT_N_NDK ntt_1536_2560 //6*256-->10*256
#define INTT_NDK_DK intt_2560_1024 //10*256-->4*256

#define NTT_K_NK ntt_768_2304 //3*256-->9*256
#define NTT_N_NK ntt_1536_2304 //6*256-->9*256
#define INTT_NK_NK_INV intt_2304_2304_inv //9*256-->9*256

#define NTT_DK_DK_INV ntt_1024_1024_inv //4*256-->4*256
#define NTT_K_DK ntt_768_1024 //3*256-->4*256
#define INTT_DK_D intt_1024_256 //4*256-->1*256

#define NTT_NK_NDK ntt_2304_2560 //9*256-->10*256
#define INTT_NDK_D intt_2560_256 //10*256-->1*256

#define T 7

/* the standard deviation of binomial sampler is sqrt(k/2)=1.58 */
#define BINOMIAL_K 4
#define BINOMIAL_BYTE 1
#define BINOMIAL_ADDMASK 0x11
#define BINOMIAL_MASK 0x0f
#define BINOMIAL_SHIFT 4
#define LOAD_BINOMIAL load_8

/* B_1/2=256 and B_2/2=512 */
#define B_1_BIT 8 /* 2^8=256 */
#define B_1_BITMASK ((1 << B_1_BIT) - 1)

#define B_2_BIT 9 /* 2^9=512 */
#define B_2_BITMASK ((1 << B_2_BIT) - 1)

#define NUM_B1 3384 /* Ndec1 */

#define B_BYTE 2 /* 2 random bytes to sample a number in Z_B */
#define LOAD_B load_16

/* c_2 compression bit number
 * discard the least significant 12 bits to make each c_2 coordinate fit in one byte */
#define C2_COMPRESSION_BITS 12
#define C2_COMPRESSION_BYTE 1
#define LOAD_C2 load_8
#define STORE_C2 store_8

#define MONTGOMERY_FACTOR 1879785471
#define MONTGOMERY_SHIFT 32

#define BARRETT_BITSHIFT_SHORT 32
#define BARRETT_FACTOR_SHORT 5825

#define BARRETT_BITSHIFT_4Q2 41 
#define BARRETT_FACTOR_4Q2 2982612

#define BARRETT_BITSHIFT_ZQ (ZQ_BYTES * 8) 
#define BARRETT_FACTOR_ZQ 22

#endif

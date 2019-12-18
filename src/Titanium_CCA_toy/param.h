/* ****************************** *
 * Titanium_CCA_toy               *
 * Implemented by Raymond K. ZHAO *
 *                                *
 * Parameters                     *
 * ****************************** */
 
#ifndef PARAM_H
#define PARAM_H

#define CRYPTO_RANDOMBYTES 32

#define Q 471041
#define Q2 (Q << 1) /* Q*2 */
#define Q_BITS 19 /* 19 bits for a number in Z_q */

#define ZQ_BYTES 3 /* 3 random bytes to sample a number in Z_q */
#define LOAD_ZQ load_24

/* the actual number of random coordinates generated by sampler_zq */
#define ZQ_BYTPCS 1370
#define ZQ_BYTPCA 750

#define N 768
#define N_act 684 /* actual N */

#define K 255

#define D 256
#define D_BYTES 32 /* 256 --> 32 bytes */

/* function names of the NTTs */
#define NTT_N_NDK ntt_768_1280 /* 3*256-->5*256 */
#define INTT_NDK_DK intt_1280_512 /* 5*256-->2*256 */

#define NTT_K_NK ntt_256_1024 /* 1*256-->4*256 */
#define NTT_N_NK ntt_768_1024 /* 3*256-->4*256 */
#define INTT_NK_NK_INV intt_1024_1024_inv /* 4*256-->4*256 */

#define NTT_DK_DK_INV ntt_512_512_inv /* 2*256-->2*256 */
#define INTT_DK_D intt_512_256 /* 2*256-->1*256 */

#define NTT_NK_NDK ntt_1024_1280 /* 4*256-->5*256 */
#define INTT_NDK_D intt_1280_256 /* 5*256-->1*256 */

#define T 10

/* the standard deviation of binomial sampler is sqrt(k/2)=1.41 */
#define BINOMIAL_K 4
#define BINOMIAL_BYTE 1
#define BINOMIAL_ADDMASK 0x11
#define BINOMIAL_MASK 0x0f
#define BINOMIAL_SHIFT 4
#define LOAD_BINOMIAL load_8

/* B_1/2=128 and B_2/2=256 */
#define B_1_BIT 7 /* 2^7=128 */
#define B_1_BITMASK ((1 << B_1_BIT) - 1)

#define B_2_BIT 8 /* 2^8=256 */
#define B_2_BITMASK ((1 << B_2_BIT) - 1)

#define NUM_B1 328 /* Ndec1 */

#define B_BYTE 1 /* 1 random bytes to sample a number in Z_B */
#define LOAD_B load_8

/* c_2 compression bit number
 * discard the least significant 11 bits to make each c_2 coordinate fit in one byte */
#define C2_COMPRESSION_BITS 11
#define C2_COMPRESSION_BYTE 1
#define LOAD_C2 load_8
#define STORE_C2 store_8

#define MONTGOMERY_FACTOR 1460088831
#define MONTGOMERY_SHIFT 32

#define BARRETT_BITSHIFT_SHORT 32
#define BARRETT_FACTOR_SHORT 9118

#define BARRETT_BITSHIFT_4Q2 40 
#define BARRETT_FACTOR_4Q2 2334216

#define BARRETT_BITSHIFT_8Q2 41 
#define BARRETT_FACTOR_8Q2 4668432

#define BARRETT_BITSHIFT_ZQ (ZQ_BYTES * 8) 
#define BARRETT_FACTOR_ZQ 35

#endif

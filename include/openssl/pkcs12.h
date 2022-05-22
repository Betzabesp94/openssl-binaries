/*
 * WARNING: do not edit!
 * Generated by makefile from include\openssl\pkcs12.h.in
 *
 * Copyright 1999-2021 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the Apache License 2.0 (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */



#ifndef OPENSSL_PKCS12_H
# define OPENSSL_PKCS12_H
# pragma once

# include <openssl/macros.h>
# ifndef OPENSSL_NO_DEPRECATED_3_0
#  define HEADER_PKCS12_H
# endif

# include <openssl/bio.h>
# include <openssl/core.h>
# include <openssl/x509.h>
# include <openssl/pkcs12err.h>
# ifndef OPENSSL_NO_STDIO
#  include <stdio.h>
# endif

#ifdef __cplusplus
extern "C" {
#endif

# define PKCS12_KEY_ID   1
# define PKCS12_IV_ID    2
# define PKCS12_MAC_ID   3

/* Default iteration count */
# ifndef PKCS12_DEFAULT_ITER
#  define PKCS12_DEFAULT_ITER     PKCS5_DEFAULT_ITER
# endif

# define PKCS12_MAC_KEY_LENGTH 20

# define PKCS12_SALT_LEN 8

/* It's not clear if these are actually needed... */
# define PKCS12_key_gen PKCS12_key_gen_utf8
# define PKCS12_add_friendlyname PKCS12_add_friendlyname_utf8

/* MS key usage constants */

# define KEY_EX  0x10
# define KEY_SIG 0x80

typedef struct PKCS12_MAC_DATA_st PKCS12_MAC_DATA;

typedef struct PKCS12_st PKCS12;

typedef struct PKCS12_SAFEBAG_st PKCS12_SAFEBAG;

SKM_DEFINE_STACK_OF_INTERNAL(PKCS12_SAFEBAG, PKCS12_SAFEBAG, PKCS12_SAFEBAG)
#define sk_PKCS12_SAFEBAG_num(sk) OPENSSL_sk_num(ossl_check_const_PKCS12_SAFEBAG_sk_type(sk))
#define sk_PKCS12_SAFEBAG_value(sk, idx) ((PKCS12_SAFEBAG *)OPENSSL_sk_value(ossl_check_const_PKCS12_SAFEBAG_sk_type(sk), (idx)))
#define sk_PKCS12_SAFEBAG_new(cmp) ((STACK_OF(PKCS12_SAFEBAG) *)OPENSSL_sk_new(ossl_check_PKCS12_SAFEBAG_compfunc_type(cmp)))
#define sk_PKCS12_SAFEBAG_new_null() ((STACK_OF(PKCS12_SAFEBAG) *)OPENSSL_sk_new_null())
#define sk_PKCS12_SAFEBAG_new_reserve(cmp, n) ((STACK_OF(PKCS12_SAFEBAG) *)OPENSSL_sk_new_reserve(ossl_check_PKCS12_SAFEBAG_compfunc_type(cmp), (n)))
#define sk_PKCS12_SAFEBAG_reserve(sk, n) OPENSSL_sk_reserve(ossl_check_PKCS12_SAFEBAG_sk_type(sk), (n))
#define sk_PKCS12_SAFEBAG_free(sk) OPENSSL_sk_free(ossl_check_PKCS12_SAFEBAG_sk_type(sk))
#define sk_PKCS12_SAFEBAG_zero(sk) OPENSSL_sk_zero(ossl_check_PKCS12_SAFEBAG_sk_type(sk))
#define sk_PKCS12_SAFEBAG_delete(sk, i) ((PKCS12_SAFEBAG *)OPENSSL_sk_delete(ossl_check_PKCS12_SAFEBAG_sk_type(sk), (i)))
#define sk_PKCS12_SAFEBAG_delete_ptr(sk, ptr) ((PKCS12_SAFEBAG *)OPENSSL_sk_delete_ptr(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr)))
#define sk_PKCS12_SAFEBAG_push(sk, ptr) OPENSSL_sk_push(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr))
#define sk_PKCS12_SAFEBAG_unshift(sk, ptr) OPENSSL_sk_unshift(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr))
#define sk_PKCS12_SAFEBAG_pop(sk) ((PKCS12_SAFEBAG *)OPENSSL_sk_pop(ossl_check_PKCS12_SAFEBAG_sk_type(sk)))
#define sk_PKCS12_SAFEBAG_shift(sk) ((PKCS12_SAFEBAG *)OPENSSL_sk_shift(ossl_check_PKCS12_SAFEBAG_sk_type(sk)))
#define sk_PKCS12_SAFEBAG_pop_free(sk, freefunc) OPENSSL_sk_pop_free(ossl_check_PKCS12_SAFEBAG_sk_type(sk),ossl_check_PKCS12_SAFEBAG_freefunc_type(freefunc))
#define sk_PKCS12_SAFEBAG_insert(sk, ptr, idx) OPENSSL_sk_insert(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr), (idx))
#define sk_PKCS12_SAFEBAG_set(sk, idx, ptr) ((PKCS12_SAFEBAG *)OPENSSL_sk_set(ossl_check_PKCS12_SAFEBAG_sk_type(sk), (idx), ossl_check_PKCS12_SAFEBAG_type(ptr)))
#define sk_PKCS12_SAFEBAG_find(sk, ptr) OPENSSL_sk_find(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr))
#define sk_PKCS12_SAFEBAG_find_ex(sk, ptr) OPENSSL_sk_find_ex(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr))
#define sk_PKCS12_SAFEBAG_find_all(sk, ptr, pnum) OPENSSL_sk_find_all(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_type(ptr), pnum)
#define sk_PKCS12_SAFEBAG_sort(sk) OPENSSL_sk_sort(ossl_check_PKCS12_SAFEBAG_sk_type(sk))
#define sk_PKCS12_SAFEBAG_is_sorted(sk) OPENSSL_sk_is_sorted(ossl_check_const_PKCS12_SAFEBAG_sk_type(sk))
#define sk_PKCS12_SAFEBAG_dup(sk) ((STACK_OF(PKCS12_SAFEBAG) *)OPENSSL_sk_dup(ossl_check_const_PKCS12_SAFEBAG_sk_type(sk)))
#define sk_PKCS12_SAFEBAG_deep_copy(sk, copyfunc, freefunc) ((STACK_OF(PKCS12_SAFEBAG) *)OPENSSL_sk_deep_copy(ossl_check_const_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_copyfunc_type(copyfunc), ossl_check_PKCS12_SAFEBAG_freefunc_type(freefunc)))
#define sk_PKCS12_SAFEBAG_set_cmp_func(sk, cmp) ((sk_PKCS12_SAFEBAG_compfunc)OPENSSL_sk_set_cmp_func(ossl_check_PKCS12_SAFEBAG_sk_type(sk), ossl_check_PKCS12_SAFEBAG_compfunc_type(cmp)))


typedef struct pkcs12_bag_st PKCS12_BAGS;

# define PKCS12_ERROR    0
# define PKCS12_OK       1

/* Compatibility macros */

#ifndef OPENSSL_NO_DEPRECATED_1_1_0

# define M_PKCS12_bag_type PKCS12_bag_type
# define M_PKCS12_cert_bag_type PKCS12_cert_bag_type
# define M_PKCS12_crl_bag_type PKCS12_cert_bag_type

# define PKCS12_certbag2x509 PKCS12_SAFEBAG_get1_cert
# define PKCS12_certbag2scrl PKCS12_SAFEBAG_get1_crl
# define PKCS12_bag_type PKCS12_SAFEBAG_get_nid
# define PKCS12_cert_bag_type PKCS12_SAFEBAG_get_bag_nid
# define PKCS12_x5092certbag PKCS12_SAFEBAG_create_cert
# define PKCS12_x509crl2certbag PKCS12_SAFEBAG_create_crl
# define PKCS12_MAKE_KEYBAG PKCS12_SAFEBAG_create0_p8inf
# define PKCS12_MAKE_SHKEYBAG PKCS12_SAFEBAG_create_pkcs8_encrypt

#endif
#ifndef OPENSSL_NO_DEPRECATED_1_1_0
OSSL_DEPRECATEDIN_1_1_0 ASN1_TYPE *PKCS12_get_attr(const PKCS12_SAFEBAG *bag,
                                                   int attr_nid);
#endif

ASN1_TYPE *PKCS8_get_attr(PKCS8_PRIV_KEY_INFO *p8, int attr_nid);
int PKCS12_mac_present(const PKCS12 *p12);
void PKCS12_get0_mac(const ASN1_OCTET_STRING **pmac,
                     const X509_ALGOR **pmacalg,
                     const ASN1_OCTET_STRING **psalt,
                     const ASN1_INTEGER **piter,
                     const PKCS12 *p12);

const ASN1_TYPE *PKCS12_SAFEBAG_get0_attr(const PKCS12_SAFEBAG *bag,
                                          int attr_nid);
const ASN1_OBJECT *PKCS12_SAFEBAG_get0_type(const PKCS12_SAFEBAG *bag);
int PKCS12_SAFEBAG_get_nid(const PKCS12_SAFEBAG *bag);
int PKCS12_SAFEBAG_get_bag_nid(const PKCS12_SAFEBAG *bag);
const ASN1_TYPE *PKCS12_SAFEBAG_get0_bag_obj(const PKCS12_SAFEBAG *bag);
const ASN1_OBJECT *PKCS12_SAFEBAG_get0_bag_type(const PKCS12_SAFEBAG *bag);

X509 *PKCS12_SAFEBAG_get1_cert(const PKCS12_SAFEBAG *bag);
X509_CRL *PKCS12_SAFEBAG_get1_crl(const PKCS12_SAFEBAG *bag);
const STACK_OF(PKCS12_SAFEBAG) *
PKCS12_SAFEBAG_get0_safes(const PKCS12_SAFEBAG *bag);
const PKCS8_PRIV_KEY_INFO *PKCS12_SAFEBAG_get0_p8inf(const PKCS12_SAFEBAG *bag);
const X509_SIG *PKCS12_SAFEBAG_get0_pkcs8(const PKCS12_SAFEBAG *bag);

PKCS12_SAFEBAG *PKCS12_SAFEBAG_create_cert(X509 *x509);
PKCS12_SAFEBAG *PKCS12_SAFEBAG_create_crl(X509_CRL *crl);
PKCS12_SAFEBAG *PKCS12_SAFEBAG_create_secret(int type, int vtype, const unsigned char *value, int len);
PKCS12_SAFEBAG *PKCS12_SAFEBAG_create0_p8inf(PKCS8_PRIV_KEY_INFO *p8);
PKCS12_SAFEBAG *PKCS12_SAFEBAG_create0_pkcs8(X509_SIG *p8);
PKCS12_SAFEBAG *PKCS12_SAFEBAG_create_pkcs8_encrypt(int pbe_nid,
                                                    const char *pass,
                                                    int passlen,
                                                    unsigned char *salt,
                                                    int saltlen, int iter,
                                                    PKCS8_PRIV_KEY_INFO *p8inf);
PKCS12_SAFEBAG *PKCS12_SAFEBAG_create_pkcs8_encrypt_ex(int pbe_nid,
                                                       const char *pass,
                                                       int passlen,
                                                       unsigned char *salt,
                                                       int saltlen, int iter,
                                                       PKCS8_PRIV_KEY_INFO *p8inf,
                                                       OSSL_LIB_CTX *ctx,
                                                       const char *propq);

PKCS12_SAFEBAG *PKCS12_item_pack_safebag(void *obj, const ASN1_ITEM *it,
                                         int nid1, int nid2);
PKCS8_PRIV_KEY_INFO *PKCS8_decrypt(const X509_SIG *p8, const char *pass,
                                   int passlen);
PKCS8_PRIV_KEY_INFO *PKCS8_decrypt_ex(const X509_SIG *p8, const char *pass,
                                      int passlen, OSSL_LIB_CTX *ctx,
                                      const char *propq);
PKCS8_PRIV_KEY_INFO *PKCS12_decrypt_skey(const PKCS12_SAFEBAG *bag,
                                         const char *pass, int passlen);
PKCS8_PRIV_KEY_INFO *PKCS12_decrypt_skey_ex(const PKCS12_SAFEBAG *bag,
                                            const char *pass, int passlen,
                                            OSSL_LIB_CTX *ctx,
                                            const char *propq);
X509_SIG *PKCS8_encrypt(int pbe_nid, const EVP_CIPHER *cipher,
                        const char *pass, int passlen, unsigned char *salt,
                        int saltlen, int iter, PKCS8_PRIV_KEY_INFO *p8);
X509_SIG *PKCS8_encrypt_ex(int pbe_nid, const EVP_CIPHER *cipher,
                           const char *pass, int passlen, unsigned char *salt,
                           int saltlen, int iter, PKCS8_PRIV_KEY_INFO *p8,
                           OSSL_LIB_CTX *ctx, const char *propq);
X509_SIG *PKCS8_set0_pbe(const char *pass, int passlen,
                        PKCS8_PRIV_KEY_INFO *p8inf, X509_ALGOR *pbe);
X509_SIG *PKCS8_set0_pbe_ex(const char *pass, int passlen,
                            PKCS8_PRIV_KEY_INFO *p8inf, X509_ALGOR *pbe,
                            OSSL_LIB_CTX *ctx, const char *propq);
PKCS7 *PKCS12_pack_p7data(STACK_OF(PKCS12_SAFEBAG) *sk);
STACK_OF(PKCS12_SAFEBAG) *PKCS12_unpack_p7data(PKCS7 *p7);
PKCS7 *PKCS12_pack_p7encdata(int pbe_nid, const char *pass, int passlen,
                             unsigned char *salt, int saltlen, int iter,
                             STACK_OF(PKCS12_SAFEBAG) *bags);
PKCS7 *PKCS12_pack_p7encdata_ex(int pbe_nid, const char *pass, int passlen,
                                unsigned char *salt, int saltlen, int iter,
                                STACK_OF(PKCS12_SAFEBAG) *bags,
                                OSSL_LIB_CTX *ctx, const char *propq);

STACK_OF(PKCS12_SAFEBAG) *PKCS12_unpack_p7encdata(PKCS7 *p7, const char *pass,
                                                  int passlen);

int PKCS12_pack_authsafes(PKCS12 *p12, STACK_OF(PKCS7) *safes);
STACK_OF(PKCS7) *PKCS12_unpack_authsafes(const PKCS12 *p12);

int PKCS12_add_localkeyid(PKCS12_SAFEBAG *bag, unsigned char *name,
                          int namelen);
int PKCS12_add_friendlyname_asc(PKCS12_SAFEBAG *bag, const char *name,
                                int namelen);
int PKCS12_add_friendlyname_utf8(PKCS12_SAFEBAG *bag, const char *name,
                                 int namelen);
int PKCS12_add_CSPName_asc(PKCS12_SAFEBAG *bag, const char *name,
                           int namelen);
int PKCS12_add_friendlyname_uni(PKCS12_SAFEBAG *bag,
                                const unsigned char *name, int namelen);
int PKCS12_add1_attr_by_NID(PKCS12_SAFEBAG *bag, int nid, int type,
                            const unsigned char *bytes, int len);
int PKCS12_add1_attr_by_txt(PKCS12_SAFEBAG *bag, const char *attrname, int type,
                            const unsigned char *bytes, int len);
int PKCS8_add_keyusage(PKCS8_PRIV_KEY_INFO *p8, int usage);
ASN1_TYPE *PKCS12_get_attr_gen(const STACK_OF(X509_ATTRIBUTE) *attrs,
                               int attr_nid);
char *PKCS12_get_friendlyname(PKCS12_SAFEBAG *bag);
const STACK_OF(X509_ATTRIBUTE) *
PKCS12_SAFEBAG_get0_attrs(const PKCS12_SAFEBAG *bag);
unsigned char *PKCS12_pbe_crypt(const X509_ALGOR *algor,
                                const char *pass, int passlen,
                                const unsigned char *in, int inlen,
                                unsigned char **data, int *datalen,
                                int en_de);
unsigned char *PKCS12_pbe_crypt_ex(const X509_ALGOR *algor,
                                   const char *pass, int passlen,
                                   const unsigned char *in, int inlen,
                                   unsigned char **data, int *datalen,
                                   int en_de, OSSL_LIB_CTX *libctx,
                                   const char *propq);
void *PKCS12_item_decrypt_d2i(const X509_ALGOR *algor, const ASN1_ITEM *it,
                              const char *pass, int passlen,
                              const ASN1_OCTET_STRING *oct, int zbuf);
void *PKCS12_item_decrypt_d2i_ex(const X509_ALGOR *algor, const ASN1_ITEM *it,
                                 const char *pass, int passlen,
                                 const ASN1_OCTET_STRING *oct, int zbuf,
                                 OSSL_LIB_CTX *libctx, 
                                 const char *propq);
ASN1_OCTET_STRING *PKCS12_item_i2d_encrypt(X509_ALGOR *algor,
                                           const ASN1_ITEM *it,
                                           const char *pass, int passlen,
                                           void *obj, int zbuf);
ASN1_OCTET_STRING *PKCS12_item_i2d_encrypt_ex(X509_ALGOR *algor,
                                              const ASN1_ITEM *it,
                                              const char *pass, int passlen,
                                              void *obj, int zbuf,
                                              OSSL_LIB_CTX *ctx,
                                              const char *propq);
PKCS12 *PKCS12_init(int mode);
PKCS12 *PKCS12_init_ex(int mode, OSSL_LIB_CTX *ctx, const char *propq);

int PKCS12_key_gen_asc(const char *pass, int passlen, unsigned char *salt,
                       int saltlen, int id, int iter, int n,
                       unsigned char *out, const EVP_MD *md_type);
int PKCS12_key_gen_asc_ex(const char *pass, int passlen, unsigned char *salt,
                          int saltlen, int id, int iter, int n,
                          unsigned char *out, const EVP_MD *md_type,
                          OSSL_LIB_CTX *ctx, const char *propq);
int PKCS12_key_gen_uni(unsigned char *pass, int passlen, unsigned char *salt,
                       int saltlen, int id, int iter, int n,
                       unsigned char *out, const EVP_MD *md_type);
int PKCS12_key_gen_uni_ex(unsigned char *pass, int passlen, unsigned char *salt,
                          int saltlen, int id, int iter, int n,
                          unsigned char *out, const EVP_MD *md_type,
                          OSSL_LIB_CTX *ctx, const char *propq);
int PKCS12_key_gen_utf8(const char *pass, int passlen, unsigned char *salt,
                        int saltlen, int id, int iter, int n,
                        unsigned char *out, const EVP_MD *md_type);
int PKCS12_key_gen_utf8_ex(const char *pass, int passlen, unsigned char *salt,
                           int saltlen, int id, int iter, int n,
                           unsigned char *out, const EVP_MD *md_type,
                           OSSL_LIB_CTX *ctx, const char *propq);

int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                        ASN1_TYPE *param, const EVP_CIPHER *cipher,
                        const EVP_MD *md_type, int en_de);
int PKCS12_PBE_keyivgen_ex(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
                           ASN1_TYPE *param, const EVP_CIPHER *cipher,
                           const EVP_MD *md_type, int en_de,
                           OSSL_LIB_CTX *libctx, const char *propq);
int PKCS12_gen_mac(PKCS12 *p12, const char *pass, int passlen,
                   unsigned char *mac, unsigned int *maclen);
int PKCS12_verify_mac(PKCS12 *p12, const char *pass, int passlen);
int PKCS12_set_mac(PKCS12 *p12, const char *pass, int passlen,
                   unsigned char *salt, int saltlen, int iter,
                   const EVP_MD *md_type);
int PKCS12_setup_mac(PKCS12 *p12, int iter, unsigned char *salt,
                     int saltlen, const EVP_MD *md_type);
unsigned char *OPENSSL_asc2uni(const char *asc, int asclen,
                               unsigned char **uni, int *unilen);
char *OPENSSL_uni2asc(const unsigned char *uni, int unilen);
unsigned char *OPENSSL_utf82uni(const char *asc, int asclen,
                                unsigned char **uni, int *unilen);
char *OPENSSL_uni2utf8(const unsigned char *uni, int unilen);

DECLARE_ASN1_FUNCTIONS(PKCS12)
DECLARE_ASN1_FUNCTIONS(PKCS12_MAC_DATA)
DECLARE_ASN1_FUNCTIONS(PKCS12_SAFEBAG)
DECLARE_ASN1_FUNCTIONS(PKCS12_BAGS)

DECLARE_ASN1_ITEM(PKCS12_SAFEBAGS)
DECLARE_ASN1_ITEM(PKCS12_AUTHSAFES)

void PKCS12_PBE_add(void);
int PKCS12_parse(PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert,
                 STACK_OF(X509) **ca);
PKCS12 *PKCS12_create(const char *pass, const char *name, EVP_PKEY *pkey,
                      X509 *cert, STACK_OF(X509) *ca, int nid_key, int nid_cert,
                      int iter, int mac_iter, int keytype);
PKCS12 *PKCS12_create_ex(const char *pass, const char *name, EVP_PKEY *pkey,
                         X509 *cert, STACK_OF(X509) *ca, int nid_key, int nid_cert,
                         int iter, int mac_iter, int keytype,
                         OSSL_LIB_CTX *ctx, const char *propq);

PKCS12_SAFEBAG *PKCS12_add_cert(STACK_OF(PKCS12_SAFEBAG) **pbags, X509 *cert);
PKCS12_SAFEBAG *PKCS12_add_key(STACK_OF(PKCS12_SAFEBAG) **pbags,
                               EVP_PKEY *key, int key_usage, int iter,
                               int key_nid, const char *pass);
PKCS12_SAFEBAG *PKCS12_add_key_ex(STACK_OF(PKCS12_SAFEBAG) **pbags,
                                  EVP_PKEY *key, int key_usage, int iter,
                                  int key_nid, const char *pass,
                                  OSSL_LIB_CTX *ctx, const char *propq);

PKCS12_SAFEBAG *PKCS12_add_secret(STACK_OF(PKCS12_SAFEBAG) **pbags,
                                  int nid_type, const unsigned char *value, int len);
int PKCS12_add_safe(STACK_OF(PKCS7) **psafes, STACK_OF(PKCS12_SAFEBAG) *bags,
                    int safe_nid, int iter, const char *pass);
int PKCS12_add_safe_ex(STACK_OF(PKCS7) **psafes, STACK_OF(PKCS12_SAFEBAG) *bags,
                       int safe_nid, int iter, const char *pass,
                       OSSL_LIB_CTX *ctx, const char *propq);

PKCS12 *PKCS12_add_safes(STACK_OF(PKCS7) *safes, int p7_nid);
PKCS12 *PKCS12_add_safes_ex(STACK_OF(PKCS7) *safes, int p7_nid,
                            OSSL_LIB_CTX *ctx, const char *propq);

int i2d_PKCS12_bio(BIO *bp, const PKCS12 *p12);
# ifndef OPENSSL_NO_STDIO
int i2d_PKCS12_fp(FILE *fp, const PKCS12 *p12);
# endif
PKCS12 *d2i_PKCS12_bio(BIO *bp, PKCS12 **p12);
# ifndef OPENSSL_NO_STDIO
PKCS12 *d2i_PKCS12_fp(FILE *fp, PKCS12 **p12);
# endif
int PKCS12_newpass(PKCS12 *p12, const char *oldpass, const char *newpass);

# ifdef  __cplusplus
}
# endif
#endif

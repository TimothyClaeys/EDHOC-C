#include "edhoc/edhoc.h"
#include "cipher_suites.h"

static const method_t auth_methods_supported[] =
        {
#if defined(EDHOC_AUTH_METHOD_0_ENABLED)
                {
                        EDHOC_AUTH_SIGN_SIGN,
                        "EDHOC_AUTH_SIGN_SIGN"
                },
#endif
#if defined(EDHOC_AUTH_METHOD_1_ENABLED)
                {
                        EDHOC_AUTH_SIGN_STATIC,
                        "EDHOC_AUTH_SIGN_STATIC"
                },
#endif
#if defined(EDHOC_AUTH_METHOD_2_ENABLED)
                {
                        EDHOC_AUTH_STATIC_SIGN,
                        "EDHOC_AUTH_STATIC_SIGN"
                },
#endif
#if defined(EDHOC_AUTH_METHOD_3_ENABLED)
                {
                        EDHOC_AUTH_STATIC_STATIC,
                        "EDHOC_AUTH_STATIC_STATIC"
                },
#endif
        };

static const cipher_suite_t ciphersuites_supported[] =
        {
#if defined(EDHOC_CIPHER_SUITE_0_ENABLED)
                {
                        EDHOC_CIPHER_SUITE_0,
                        "EDHOC_CIPHER_SUITE_0",
                        COSE_KTY_OCTET,
                        COSE_ALGO_AESCCM_16_64_128,
                        COSE_ALGO_SHA256,
                        COSE_EC_CURVE_X25519,
                        COSE_ALGO_EDDSA,
                        COSE_EC_CURVE_ED25519,
                        COSE_ALGO_AESCCM_16_64_128,
                        COSE_ALGO_SHA256
                },
#endif
#if defined(EDHOC_CIPHER_SUITE_1_ENABLED)
                {
                        EDHOC_CIPHER_SUITE_1,
                        "EDHOC_CIPHER_SUITE_1",
                        COSE_KTY_OCTET,
                        COSE_ALGO_AESCCM_16_128_128,
                        COSE_ALGO_SHA256,
                        COSE_EC_CURVE_X25519,
                        COSE_ALGO_EDDSA,
                        COSE_EC_CURVE_ED25519,
                        COSE_ALGO_AESCCM_16_64_128,
                        COSE_ALGO_SHA256
                },
#endif
#if defined(EDHOC_CIPHER_SUITE_2_ENABLED)
                {
                        EDHOC_CIPHER_SUITE_2,
                        "EDHOC_CIPHER_SUITE_2",
                        COSE_KTY_EC2,
                        COSE_ALGO_AESCCM_16_64_128,
                        COSE_ALGO_SHA256,
                        COSE_EC_CURVE_P256,
                        COSE_ALGO_ES256,
                        COSE_EC_CURVE_P256,
                        COSE_ALGO_AESCCM_16_64_128,
                        COSE_ALGO_SHA256
                },
#endif
#if defined(EDHOC_CIPHER_SUITE_3_ENABLED)
                {
                        EDHOC_CIPHER_SUITE_3,
                        "EDHOC_CIPHER_SUITE_3",
                        COSE_ALGO_AESCCM_16_128_128,
                        COSE_ALGO_SHA256,
                        COSE_EC_CURVE_P256,
                        COSE_ALGO_ES256,
                        COSE_EC_CURVE_P256,
                        COSE_ALGO_AESCCM_16_64_128,
                        COSE_ALGO_SHA256
                },
#endif
        };


const cipher_suite_t *edhoc_supported_suites(void) {
    return ciphersuites_supported;
}

size_t edhoc_supported_suites_len(void) {
    return sizeof(ciphersuites_supported) / sizeof(cipher_suite_t);
}

size_t edhoc_auth_methods_len(void) {
    return sizeof(auth_methods_supported) / sizeof(method_t);
}

const method_t *edhoc_auth_method_from_id(uint8_t method) {
    for (size_t i = 0; i < edhoc_auth_methods_len(); i++) {
        if (method == auth_methods_supported[i].id) {
            return &auth_methods_supported[i];
        }
    }

    return NULL;
}

const cipher_suite_t *edhoc_cipher_suite_from_id(uint8_t cipher_suite) {
    for (size_t i = 0; i < edhoc_supported_suites_len(); i++) {
        if (cipher_suite == ciphersuites_supported[i].id) {
            return &ciphersuites_supported[i];
        }
    }

    return NULL;
}

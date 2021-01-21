#ifndef EDHOC_CBOR_CERTS_H
#define EDHOC_CBOR_CERTS_H

typedef struct cbor_cert cbor_cert_t;

struct cbor_cert{
    uint8_t *type;
    uint16_t *serial_number;
    char* issuer;
    int* validity;
    uint8_t* subject;
    size_t subject_len;
    uint8_t* signature;
    const uint8_t* cert;
    size_t cert_len;
};

/*
 * @brief Load a CBOR certificate. The certificate is decoded and it populates the cbor_cert_t
 * structure.
 *
 * @param[in,out] cert_ctx      A CBOR cert structure that will get populated.
 * @param[in] certificate       A CBOR encoded certificate (native).
 * @param[in] length            The length of the CBOR certificate.
 *
 * @returns  i
 */
int cbor_cert_load_from_cbor(cbor_cert_t *cert_ctx, const uint8_t* certificate, size_t length);



#endif /* EDHOC_CBOR_CERTS_H */
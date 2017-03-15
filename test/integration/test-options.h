#ifndef TEST_OPTIONS_H
#define TEST_OPTIONS_H

#include "sapi/tpm20.h"

/* Default TCTI */
#define TCTI_DEFAULT      TABRMD_TCTI
#define TCTI_DEFAULT_STR  "tabrmd"

/* Defaults for Device TCTI */
#define DEVICE_PATH_DEFAULT "/dev/tpm0"

/* Deafults for Socket TCTI connections */
#define HOSTNAME_DEFAULT "127.0.0.1"
#define PORT_DEFAULT     2321

/* environment variables holding TCTI config */
#define ENV_TCTI_NAME      "TPM20TEST_TCTI_NAME"
#define ENV_DEVICE_FILE    "TPM2OTEST_DEVICE_FILE"
#define ENV_SOCKET_ADDRESS "TPM20TEST_SOCKET_ADDRESS"
#define ENV_SOCKET_PORT    "TPM20TEST_SOCKET_PORT"


typedef enum {
    UNKNOWN_TCTI,
    DEVICE_TCTI,
    SOCKET_TCTI,
    TABRMD_TCTI,
    N_TCTI,
} TCTI_TYPE;

typedef struct {
    TCTI_TYPE tcti_type;
    char     *device_file;
    char     *socket_address;
    uint16_t  socket_port;
} test_opts_t;

/* functions to get test options from the user and to print helpful stuff */
char* const  tcti_name_from_type        (TCTI_TYPE             tcti_type);
TCTI_TYPE    tcti_type_from_name        (char const           *tcti_str);
int          get_test_opts_from_env     (test_opts_t          *opts);
int          sanity_check_test_opts     (test_opts_t          *opts);
void         dump_test_opts             (test_opts_t          *opts);

#endif /* TEST_OPTIONS_H */
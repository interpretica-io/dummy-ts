/** @file
 * @brief SUT smoke test — runs the SUT binary and checks exit code.
 *
 * Copyright (C) 2025-2026 Interpretica Unipessoal Lda
 *
 * @author Maxim Menshikov <maxim.menshikov@interpretica.io>
 *
 * $Id: $
 */

#define TE_TEST_NAME "experiment/sut_test"

#include <sys/wait.h>
#include "te_config.h"
#include "tapi_test.h"

int
main(int argc, char **argv)
{
    const char *sut_bin;
    int         status;

    TEST_START;

    TEST_GET_STRING_PARAM(sut_bin);

    if (sut_bin == NULL || *sut_bin == '\0')
        TEST_SKIP("sut_bin not set — no SUT configured");

    TEST_STEP("Run SUT binary: %s", sut_bin);
    status = system(sut_bin);
    rc = WIFEXITED(status) ? WEXITSTATUS(status) : -1;
    if (rc != 0)
        TEST_VERDICT("SUT exited with non-zero status: %d", rc);

    TEST_SUCCESS;
cleanup:
    TEST_END;
}

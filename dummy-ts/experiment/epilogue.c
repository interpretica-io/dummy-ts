/** @file
 * @brief Experiment Group
 *
 * Experiment group epilogue.
 *
 * Copyright (C) 2025-2026 Interpretica Unipessoal Lda
 *
 * @author Maxim Menshikov <maxim.menshikov@interpretica.io>
 *
 * $Id: $
 */

#define TE_TEST_NAME    "experiment/epilogue"

#include "te_config.h"
#include "tapi_test.h"
#include "tsapi_evo.h"

int
main(int argc, char **argv)
{
    TEST_START;

    tsapi_evo_analysis_hint("Experiment group epilogue. Cleaning up after experiment tests.");

    TEST_STEP("Clean up experiment group");
    /* No actions required */

    TEST_SUCCESS;

cleanup:

    TEST_END;
}
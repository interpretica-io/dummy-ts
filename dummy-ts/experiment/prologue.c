/** @file
 * @brief Experiment Group
 *
 * Experiment group prologue.
 *
 * Copyright (C) 2025-2026 Interpretica Unipessoal Lda
 *
 * @author Maxim Menshikov <maxim.menshikov@interpretica.io>
 *
 * $Id: $
 */

#define TE_TEST_NAME    "experiment/prologue"

#include "te_config.h"
#include "tapi_test.h"
#include "tsapi_evo.h"

int
main(int argc, char **argv)
{
    TEST_START;

    tsapi_evo_analysis_hint("Experiment group prologue. Preparing the environment for experiment tests.");

    TEST_STEP("Prepare experiment group");
    /* No actions required for this experiment group */

    TEST_SUCCESS;

cleanup:

    TEST_END;
}
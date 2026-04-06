/** @file
 * @brief Experiment Group
 *
 * Dummy experiment test demonstrating charts, verdicts, and iteration results.
 *
 * Copyright (C) 2025-2026 Interpretica Unipessoal Lda
 *
 * @author Maxim Menshikov <maxim.menshikov@interpretica.io>
 *
 * $Id: $
 */

#define TE_TEST_NAME    "experiment/dummy_test"

#include "te_config.h"
#include "tapi_test.h"
#include "tsapi_evo.h"

typedef enum dummy_scenario {
    DUMMY_SCENARIO_PASS,
    DUMMY_SCENARIO_FAIL,
    DUMMY_SCENARIO_EXPECTED_FAIL,
} dummy_scenario;

#define DUMMY_SCENARIO_LIST \
    { "pass",          DUMMY_SCENARIO_PASS          }, \
    { "fail",          DUMMY_SCENARIO_FAIL          }, \
    { "expected_fail", DUMMY_SCENARIO_EXPECTED_FAIL }

int
main(int argc, char **argv)
{
    dummy_scenario   scenario;
    tsapi_evo_schart chart;
    int              metric_value;
    const char      *explanation;
    const char      *scenario_label;
    char             metric_str[32];

    TEST_START;

    TEST_STEP("Parse test parameters");
    TEST_GET_ENUM_PARAM(scenario, DUMMY_SCENARIO_LIST);

    tsapi_evo_analysis_hint(
        "Experiment dummy test. Three iterations: one passes, one fails "
        "unexpectedly, one fails expectedly (known issue).");

    TEST_STEP("Initialize experiment chart");
    tsapi_evo_schart_init(&chart, "Experiment", "Dummy Metric / Scenario",
                          "0", "units");

    switch (scenario)
    {
        case DUMMY_SCENARIO_PASS:
            TEST_STEP("Simulate passing scenario");
            metric_value   = 42;
            scenario_label = "pass";
            explanation    = NULL;
            break;

        case DUMMY_SCENARIO_FAIL:
            TEST_STEP("Simulate unexpected failing scenario");
            metric_value   = 0;
            scenario_label = "fail";
            explanation    = "Unexpected failure: metric is below threshold";
            break;

        case DUMMY_SCENARIO_EXPECTED_FAIL:
            TEST_STEP("Simulate expected failing scenario");
            metric_value   = 0;
            scenario_label = "expected_fail";
            explanation    = "Expected failure: known issue";
            break;

        default:
            TEST_FAIL("Unknown scenario value: %d", scenario);
    }

    TEST_STEP("Record metric in chart");
    sprintf(metric_str, "%d", metric_value);
    tsapi_evo_schart_add_metric(&chart, scenario_label, metric_str,
                                explanation);

    TEST_STEP("Print and finalize chart");
    tsapi_evo_schart_print(&chart);
    tsapi_evo_schart_fini(&chart);

    if (scenario == DUMMY_SCENARIO_FAIL)
    {
        TEST_VERDICT("Experiment iteration failed: metric is below "
                     "threshold (got 0, expected > 0)");
    }
    else if (scenario == DUMMY_SCENARIO_EXPECTED_FAIL)
    {
        TEST_VERDICT("Experiment iteration failed: known issue "
                     "(expected failure)");
    }

    TEST_SUCCESS;

cleanup:

    TEST_END;
}
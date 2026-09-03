# Dummy Test Suite

Minimal test suite skeleton built on the [Test Environment](https://ts-factory.io/) framework.

## Structure

```
dummy-ts/
├── dummy-ts/               # Test suite source
│   ├── lib/                # tsapi_evo — charts and hints library
│   ├── experiment/         # Experiment test group
│   │   ├── prologue.c      # Group prologue
│   │   ├── epilogue.c      # Group epilogue
│   │   └── dummy_test.c    # Test with charts, verdicts, two iterations
│   ├── prologue.c          # Suite prologue
│   └── epilogue.c          # Suite epilogue
├── conf/                   # Configuration
│   ├── run.conf.localhost  # Localhost run config
│   ├── env.localhost       # Localhost environment
│   ├── external.yml        # External TE repositories catalog
│   └── builder.conf.lock   # Commits those repositories are pinned to
└── scripts/                # Helper scripts
```

## Prerequisites

- Docker
- `test-environment` cloned alongside this repo:

```bash
git clone https://github.com/ts-factory/test-environment.git ../test-environment
```

## External modules

The suite builds a TAPI and a Test Agent type from
[tsf-dummy](https://github.com/interpretica-io/tsf-dummy), a repository
outside the TE tree. `conf/external.yml` says which repository and which
reference to follow; `conf/builder.conf.lock` records the commit that is
actually built and is committed alongside it, so that a clean checkout on
any machine builds the very same sources.

To move to a newer commit of an external repository:

```bash
./scripts/run.sh docker guess --cfg=localhost --update-external
```

Then commit the updated `conf/builder.conf.lock`.

## Running

```bash
./scripts/run.sh docker guess --cfg=localhost
```

The suite runs two iterations of `dummy_test`:

| Iteration | `should_fail` | Result |
|-----------|---------------|--------|
| 1 | `FALSE` | pass — metric = 42 |
| 2 | `TRUE` | FAILED — metric = 0, verdict emitted |

## Results

Logs are written to the build directory after the run:

```bash
cat log.txt
```

Generate HTML:

```bash
./scripts/html-log.sh
```

## License

Copyright (C) 2025-2026 Interpretica Unipessoal Lda

## Authors

- Maxim Menshikov — <maxim.menshikov@interpretica.io>
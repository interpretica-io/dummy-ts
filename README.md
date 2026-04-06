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
│   └── env.localhost       # Localhost environment
└── scripts/                # Helper scripts
```

## Prerequisites

- Docker
- `test-environment` cloned alongside this repo:

```bash
git clone https://github.com/ts-factory/test-environment.git ../test-environment
```

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
# tigerr
Advanced C++ Error Logging Library with support for colors, error severity, and logging to console and files!<br>
Features a single-header system with only a dependancy for C++17<br>
`tigerr` is as capable as `spdlog`

| Features        | tigerr | spdlog | Boost.Log |
|----------------|-------------|-------|-------|
| Multiple logging sinks         | ✅          | ✅    | ✅    |
| Async. logging     | ❌          | ✅    | ✅    |
| Log levels         | ✅           | ✅     | ✅    |
| Colors     | ✅           | ✅    | ✅    |
| Header-only  | ✅          | ✅    | ✅    |
| Compile-time filtering  | ✅          | ✅    | ✅    |
| 100 lines of code  | ✅          | ❌    | ❌    |
| Rotating Log Files  | ❌          | ✅    | ✅    |
| Timestamps in Logs  | ❌          | ✅    | ✅    |


## Implementation
- Import `tigerr.h` in your project
- Start using the `LogError()` function

## LogError Parameters
- `errorLabel` - Error title or code
- `errorDetails` - More in-depth summary of the problems
- `errorSeverity` - Enum which determines the priority of the error
    - `DEBUG` - Only is printed/logged when in Debug mode
    - `NOTICE` - Simple logging
    - `ALERT` - An error that is bad but not critical
    - `FAILURE` - Mission-critical problem
- `asciiColor` - Boolean which controls wether or not to use ASCII color in the console
- `output` - Enum which controls the output of the error
    - `CONSOLE` - Prints error to console
    - `FILE` - Prints to a specified log file
    - Alternatively you can use 2+ of these flags `CONSOLE | FILE` -> Prints both to console and file
- `logPath` - Path to log file

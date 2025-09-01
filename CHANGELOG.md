# Version 1.0.0
First stable release

# Version 1.0.1
- Compile-time filtering
  - Logs with Severity Level `DEBUG` will not be displayed in Release Mode in MSVC or when `TIGERR_RELEASE_MODE` is enabled
- Updated logging sinks
  - Instead of writing `CONSOLE_AND_FILE` you would write `CONSOLE | FILE` (or more sinks)
- Added `LogToFile`
  - No change to end user, internal only

# Version 1.0.1B
- Updated Debug control directive
  - Switched from MSVC's _DEBUG to the cross-compiler NDEBUG

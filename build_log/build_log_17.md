# Build Log 01

**Date:** 9 July 2026 (Morning)  
**Duration:** 3.5 hours

## Goal

Implement the first working version of the `RedisLite` command-line interface capable of accepting user commands and interacting with the underlying `HashMap`.

## Problem Encountered

Initially, I implemented the command parser using `std::cin`.

This worked for reading individual tokens but failed when multiple commands were entered one after another.

For example:

```text
SET 10 
GET 10
```

After executing the first command, the remaining input stayed inside the input buffer.

As a result:

- `GET` was incorrectly read as the value of the previous `SET` command.
- `10` from the second command was interpreted as a new command during the next loop iteration.

This caused invalid command errors and incorrect command parsing.

## What I Tried

I first implemented handlers for:

- `SET`
- `GET`
- `DEL`
- `EXISTS`
- `COUNT`
- `CLEAR`
- `PRINT`
- `EXIT`

using direct `std::cin` extraction.

After observing the buffer issue, I redesigned the command parser.

Instead of reading individual tokens, I switched to:

```cpp
std::getline(std::cin, command);
```

This allowed each iteration of the loop to process one complete command line.

I then manually parsed the line into:

- command
- key
- value

while handling multiple spaces correctly.

This redesign removed the input-buffer synchronization issue.

## Outcome

Completed the first functional version of the Redis command parser.

Major learnings:

- difference between `std::cin` and `std::getline()`
- how input buffering affects command-line applications
- why complete-line parsing is more reliable for CLI programs
- manual token extraction from a command string
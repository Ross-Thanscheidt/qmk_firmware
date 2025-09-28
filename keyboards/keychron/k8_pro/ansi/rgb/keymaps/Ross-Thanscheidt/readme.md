# Keychron K8 Pro

As of September 28, 2025, I have moved my Keychron K8 Pro keymap files to the `wireless_playground_ross` branch
and will be doing future updates in that branch.

I had issues with Bluetooth initially with my keymap files in the `wireless_playground_ross` branch
with it sending the wrong characters (like when I typed a `5` it would send an `m` character).
When I removed the line defining `FORCE_NKRO` in the `config.h` file, then it worked normally.

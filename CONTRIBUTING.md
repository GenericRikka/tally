# Contributing to tally

Thank you for wanting to contribute! This document walks you through everything
from forking the repository to getting your pull request merged. Read it once
carefully — the CI pipeline will enforce most of these rules automatically, so
understanding them upfront will save you a lot of back-and-forth.

---

## Table of contents

1. [The big picture](#1-the-big-picture)
2. [Setting up your environment](#2-setting-up-your-environment)
3. [Forking and cloning](#3-forking-and-cloning)
4. [Picking an issue](#4-picking-an-issue)
5. [Creating a branch](#5-creating-a-branch)
6. [Writing code](#6-writing-code)
7. [Commit message format](#7-commit-message-format)
8. [Running checks locally](#8-running-checks-locally)
9. [Opening a pull request](#9-opening-a-pull-request)
10. [The review process](#10-the-review-process)
11. [Issue labels](#11-issue-labels)

---

## 1. The big picture

The contribution workflow looks like this:

```
upstream (this repo) ◀———————————————————————————┐
    │                                            │
    └─► your fork on GitHub                      │
            │                                    │
            └─► a branch on your fork            │
                    │                            │
                    └─► Pull Request → review → merge
```

You never push directly to `main` on the upstream repository. All changes go
through a pull request (PR), even small ones. This gives the maintainer a
chance to review and discuss the change before it lands.

---

## 2. Setting up your environment

Follow the build instructions in [README.md](README.md) for your platform.

Additionally, install `clang-format` for code style checking:

**Windows (MSYS2 MINGW64 shell):**
```bash
pacman -S mingw-w64-x86_64-clang
```

**Linux (Debian/Ubuntu):**
```bash
sudo apt install clang-format
```

---

## 3. Forking and cloning

1. Click **Fork** in the top-right corner of this repository on GitHub.
   This creates a copy of the repository under your own GitHub account.

2. Clone *your fork* (not the original) to your machine:
   ```bash
   git clone https://github.com/YOUR_USERNAME/tally.git
   cd tally
   ```

3. Add the original repository as a remote named `upstream` so you can pull
   in future changes:
   ```bash
   git remote add upstream https://github.com/GenericRikka/tally.git
   ```

4. Verify you have both remotes:
   ```bash
   git remote -v
   # origin    https://github.com/YOUR_USERNAME/tally.git (fetch)
   # origin    https://github.com/YOUR_USERNAME/tally.git (push)
   # upstream  https://github.com/GenericRikka/tally.git (fetch)
   # upstream  https://github.com/GenericRikka/tally.git (push)
   ```

---

## 4. Picking an issue

Browse the [open issues](../../issues). Issues are labelled by difficulty
(see [§11 Issue labels](#11-issue-labels)). Start with a `difficulty: easy`
issue if this is your first contribution.

Leave a comment on the issue saying you're going to work on it. This avoids
two people doing the same work at the same time.

---

## 5. Creating a branch

Always create a new branch for each issue. **Never work directly on `main`.**

First, make sure your local `main` is up to date with upstream:
```bash
git checkout main
git pull upstream main
```

Then create a branch. Name it after the type of change and the issue number:

```bash
# Pattern: <type>/<issue-number>-<short-description>
git checkout -b feat/12-add-word-count
git checkout -b fix/7-wrong-exit-code
```

The types (`feat`, `fix`, `docs`, etc.) match the commit types described in
the next section.

---

## 6. Writing code

A few things to keep in mind:

- **One logical change per PR.** If an issue requires both a refactor and a new
  feature, split them into separate PRs. Smaller PRs are reviewed faster and
  are easier to understand.
- **Keep the code style consistent.** Run `clang-format` before committing
  (see §8).
- **No warnings.** The build is configured with `-Werror`, so any compiler
  warning will be treated as an error in CI.
- **Update the tests.** If you add new behaviour, add a test for it in
  `tests/run_tests.sh`.

---

## 7. Commit message format

This project uses **[Conventional Commits](https://www.conventionalcommits.org/)**.
The CI pipeline will reject PRs that contain commits not following this format.

### Structure

```
<type>(<optional scope>): <short description>

<optional body>

<optional footer>
```

### Rules

| Part | Rule |
|---|---|
| **type** | Must be one of: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`, `ci` |
| **subject** | Lowercase, no trailing period, max 72 characters total (including `type: `) |
| **body** | Optional. Separated from subject by a blank line. Wrap at 100 characters. |
| **footer** | Optional. Use `Closes #N` to auto-close an issue on merge. |

### Examples

**Minimal (no body needed for simple changes):**
```
feat: add -w flag for word counting
```

**With scope:**
```
feat(cli): add -w flag for word counting
```

**With body and footer:**
```
feat(cli): add -w flag for word counting

Words are delimited by any sequence of whitespace characters.
The -w flag is mutually exclusive with the default line count mode.

Closes #12
```

**A fix:**
```
fix: return non-zero exit code when file is missing
```

**Documentation only:**
```
docs: add Windows build instructions to README
```

### Common mistakes

```
# ✗ Capital letter at the start
Feat: add word count

# ✗ Wrong type (not in the allowed list)
feature: add word count

# ✗ Subject too long (over 72 characters total)
feat: add -w flag that counts words by splitting on whitespace characters

# ✓ Correct
feat: add -w flag for word counting
```

---

## 8. Running checks locally

Run these before pushing to avoid a failing CI pipeline.

### Build

```bash
cmake -B build -G Ninja
cmake --build build
```

### Tests

```bash
bash tests/run_tests.sh ./build/tally        # Linux / BSD
bash tests/run_tests.sh ./build/tally.exe    # Windows (MSYS2)
```

### Code style

Check whether any files are not formatted correctly:
```bash
find src include -name '*.c' -o -name '*.h' | xargs clang-format --dry-run --Werror
```

Auto-fix formatting in-place:
```bash
find src include -name '*.c' -o -name '*.h' | xargs clang-format -i
```

---

## 9. Opening a pull request

1. Push your branch to *your fork*:
   ```bash
   git push origin feat/12-add-word-count
   ```

2. Go to your fork on GitHub. You should see a banner offering to open a PR —
   click **Compare & pull request**.

3. Fill in the PR template:
   - What does this change do?
   - Which issue does it close? (write `Closes #12` in the description)
   - Tick the checklist items

4. Submit the PR. CI will start running automatically. Wait for it to go green
   before asking for a review.

---

## 10. The review process

- The maintainer will leave comments directly on lines of your code.
- Address each comment, push new commits to the *same branch*, and reply to
  the comment to indicate you've handled it.
- Do not force-push your branch while a review is in progress — it makes it
  hard to see what changed.
- Once all comments are resolved and CI is green, the maintainer will merge
  your PR.

---

## 11. Issue labels

| Label | Meaning |
|---|---|
| `difficulty: easy` | Small, well-defined change. Good for a first contribution. |
| `difficulty: medium` | Requires a bit more thought or touches more of the codebase. |
| `difficulty: hard` | Significant change, likely involving design decisions. |
| `bug` | Something is broken. |
| `enhancement` | New feature or improvement to existing behaviour. |
| `docs` | Documentation only. |
| `good first issue` | Explicitly recommended for first-time contributors. |

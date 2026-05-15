export default {
  extends: ['@commitlint/config-conventional'],
  rules: {
    // Subject line hard limit
    'header-max-length': [2, 'always', 72],
    // Body lines hard limit
    'body-max-line-length': [2, 'always', 100],
    // Allowed types
    'type-enum': [
      2,
      'always',
      [
        'feat',   // new feature
        'fix',    // bug fix
        'docs',   // documentation only
        'style',  // formatting, no logic change
        'refactor', // neither fix nor feature
        'test',   // adding or fixing tests
        'chore',  // build process, dependencies, tooling
        'ci',     // CI/CD changes
      ],
    ],
  },
};

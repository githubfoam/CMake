# CMake-test
CMake pipeline
=========


Travis (.com) branch:
[![Travis (.com)](https://img.shields.io/travis/com/githubfoam/CMake-test.svg)](https://travis-ci.com/githubfoam/CMake-test)  


----------------

Playbook
----------------


File:

    - hosts: servers
      roles:
         - { role: githubfoam.apache }

Command:

             - $ ansible-galaxy install --roles-path . githubfoam.apache


License
-------

Apache License 2.0

Author Information
------------------

An optional section for the role authors

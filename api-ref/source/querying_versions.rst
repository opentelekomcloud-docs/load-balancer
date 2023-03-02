:original_name: elb_fl_0006.html

.. _elb_fl_0006:

Querying Versions
=================

Function
--------

Queries all available versions.

If there is no version added to the URL, all available versions are returned.

URI
---

GET /versions

Request
-------

None

Response
--------

None

Example
-------

-  Example request

   .. code-block:: text

      GET /versions

-  Example response

   .. code-block::

      {
        "versions": [
          {
            "id": "v3",
            "status": "CURRENT"
          },
          {
            "id": "v2",
            "status": "STABLE"
          },
          {
            "id": "v2.0",
            "status": "STABLE"
          }
        ]
      }

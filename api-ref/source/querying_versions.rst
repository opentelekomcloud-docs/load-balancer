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

GET /

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

      GET /

-  Example response

   .. code-block::

      {
         "versions": [
            {
                "status": "CURRENT",
                "id": "v2.0",
                "links": [
               {
                  "href": "http://192.168.82.231:9696/v2.0",
                  "rel": "self"
               }
              ]
             }
           ]
      }

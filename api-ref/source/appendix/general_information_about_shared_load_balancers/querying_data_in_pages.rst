:original_name: elb_fl_0004.html

.. _elb_fl_0004:

Querying Data in Pages
======================

APIs v2.0 allow users to query data in pages by adding the limit and marker parameters to the URL of the list request. The query results are displayed in the ascending order of IDs.

-  **next ref** in the response indicates the URL of the next page.
-  **previous ref** in the response indicates the URL of the previous page.

Request
-------

.. table:: **Table 1** Parameter description

   +--------------+--------+-----------+------------------------------------------------------------------------------------------------------------------------------+
   | Parameter    | Type   | Mandatory | Description                                                                                                                  |
   +==============+========+===========+==============================================================================================================================+
   | limit        | int    | No        | Specifies the number of records on each page.                                                                                |
   +--------------+--------+-----------+------------------------------------------------------------------------------------------------------------------------------+
   | marker       | String | No        | Specifies the resource ID of pagination query. If the parameter is left blank, only resources on the first page are queried. |
   +--------------+--------+-----------+------------------------------------------------------------------------------------------------------------------------------+
   | page_reverse | Bool   | No        | Specifies the paging sequence. The value can be **true** or **false**.                                                       |
   +--------------+--------+-----------+------------------------------------------------------------------------------------------------------------------------------+

Response
--------

None

Example
-------

-  Example request

   .. code-block:: text

      GET /v2.0/networks?limit=2&marker=3d42a0d4-a980-4613-ae76-a2cddecff054&page_reverse=False

-  Example response

   .. code-block::

      {
          "networks": [
              {
                  "status": "ACTIVE",
                  "subnets": [],
                  "name": "liudongtest ",
                  "admin_state_up": false,
                  "tenant_id": "6fbe9263116a4b68818cf1edce16bc4f",
                  "id": "60c809cb-6731-45d0-ace8-3bf5626421a9"
              },
              {
                  "status": "ACTIVE",
                  "subnets": [
                      "132dc12d-c02a-4c90-9cd5-c31669aace04"
                  ],
                  "name": "publicnet",
                  "admin_state_up": true,
                  "tenant_id": "6fbe9263116a4b68818cf1edce16bc4f",
                  "id": "9daeac7c-a98f-430f-8e38-67f9c044e299"
              }
          ],
          "networks_links": [
              {
                  "href": "http://192.168.82.231:9696/v2.0/networks?limit=2&marker=9daeac7c-a98f-430f-8e38-67f9c044e299",
                  "rel": "next"
              },
              {
                  "href": "http://192.168.82.231:9696/v2.0/networks?limit=2&marker=60c809cb-6731-45d0-ace8-3bf5626421a9&page_reverse=True",
                  "rel": "previous"
              }
          ]
      }

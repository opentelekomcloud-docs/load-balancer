:original_name: elb_zq_bq_0011.html

.. _elb_zq_bq_0011:

Querying Listeners by Tag
=========================

Function
--------

This API is used to query listeners by tag.

.. note::

   You can also use this API for dedicated load balancers.

Constraints
-----------

None

URI
---

POST /v2.0/{project_id}/listeners/resource_instances/action

.. table:: **Table 1** Parameter description

   +------------+-----------+--------+--------------------------------------------------------+
   | Parameter  | Mandatory | Type   | Description                                            |
   +============+===========+========+========================================================+
   | project_id | Yes       | String | Specifies the ID of the project where the tag is used. |
   +------------+-----------+--------+--------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ===========
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========
   X-Auth-Token Yes       String User token
   ============ ========= ====== ===========

.. table:: **Table 3** Parameter description

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
   +=================+=================+=================+==================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================================+
   | tags            | No              | Array           | Specifies the included tags. A maximum of 20 tag keys are allowed for each query operation. Each tag key can have up to 20 tag values. The structure body must be included. The tag key cannot be left blank or set to an empty string. Each tag key and each tag value of the same tag key must be unique. For details, see :ref:`Table 4 <elb_zq_bq_0011__en-us_topic_0109852832_table202620276214>`.                                                                                                                          |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | limit           | No              | Integer         | Sets the page size. This parameter is available when **action** is set to **filter**. Both the default value and maximum value are **1000**, and the minimum value is **1**. The value cannot be a negative integer.                                                                                                                                                                                                                                                                                                             |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | offset          | No              | Integer         | Specifies the index position. The query starts from the next listener indexed by this parameter. This parameter is not required when you query listeners on the first page. The value in the response returned for querying the listeners on the previous page will be included in this parameter for querying the listeners on subsequent pages. This parameter is not available when **action** is set to **count**. If **action** is set to **filter**, the value must be a positive integer, and the default value is **0**. |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | action          | Yes             | String          | Identifies the operation. The value can be **filter** or **count**.                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
   |                 |                 |                 | -  **filter**: indicates pagination query.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
   |                 |                 |                 | -  **count**: indicates that all listeners meeting the search criteria will be returned.                                                                                                                                                                                                                                                                                                                                                                                                                                         |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | matches         | No              | Array           | Specifies the search criteria. The tag key is the parameter to match, for example, **resource_name**. **value** indicates the value of the match content. The key is a fixed dictionary value.                                                                                                                                                                                                                                                                                                                                   |
   |                 |                 |                 |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
   |                 |                 |                 | Determine whether fuzzy match is required based on different parameters. For example, if the **key** is **resource_name**, fuzzy search is used by default. If **value** is an empty string, exact match is used. If the key is **resource_id**, exact match is used. Currently, only **resource_name** can be used for search. For details, see :ref:`Table 5 <elb_zq_bq_0011__en-us_topic_0109852832_table5401017132210>`.                                                                                                     |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0011__en-us_topic_0109852832_table202620276214:

.. table:: **Table 4** **tags** parameter description

   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                                                              |
   +===========+===========+========+==========================================================================================================================================================+
   | key       | Yes       | String | Specifies the tag key. It contains a maximum of 127 Unicode characters and cannot be left blank. (This parameter is not verified in the search process.) |
   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | values    | Yes       | Array  | Lists the tag values. Each tag value can contain a maximum of 255 Unicode characters. The values are in the OR relationship.                             |
   +-----------+-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0011__en-us_topic_0109852832_table5401017132210:

.. table:: **Table 5** **matches** parameter description

   +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                              |
   +=================+=================+=================+==========================================================================================+
   | key             | Yes             | String          | Specifies the tag key.                                                                   |
   |                 |                 |                 |                                                                                          |
   |                 |                 |                 | The value can be one of the following:                                                   |
   |                 |                 |                 |                                                                                          |
   |                 |                 |                 | -  **resource_name**: indicates the resource name.                                       |
   +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------+
   | value           | Yes             | String          | Specifies the tag value. Each tag value can contain a maximum of 255 Unicode characters. |
   +-----------------+-----------------+-----------------+------------------------------------------------------------------------------------------+

Response Parameters
-------------------

.. table:: **Table 6** Response parameters

   +-------------+---------+-------------------------------------------------------------------------------------------------------------------+
   | Parameter   | Type    | Description                                                                                                       |
   +=============+=========+===================================================================================================================+
   | resources   | Array   | Lists the listeners. For details, see :ref:`Table 7 <elb_zq_bq_0011__en-us_topic_0109852832_table2019842119305>`. |
   +-------------+---------+-------------------------------------------------------------------------------------------------------------------+
   | total_count | Integer | Specifies the total number of queried records.                                                                    |
   +-------------+---------+-------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0011__en-us_topic_0109852832_table2019842119305:

.. table:: **Table 7** **resource** parameter description

   +-------------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter         | Type   | Description                                                                                                                                                          |
   +===================+========+======================================================================================================================================================================+
   | resource_id       | String | Specifies the resource ID.                                                                                                                                           |
   +-------------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | resource_detail   | String | Specifies the resource details. The value is a resource object, used for extension. The value is left blank by default.                                              |
   +-------------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | tags              | Array  | Lists the tags. If there is no tag, an empty array is used by default. For details, see :ref:`Table 8 <elb_zq_bq_0011__en-us_topic_0109852832_table15683233145412>`. |
   +-------------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | resource_name     | String | Specifies the resource name. This parameter is an empty string by default if there is no resource name.                                                              |
   +-------------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | super_resource_id | String | Specifies the parent resource ID.                                                                                                                                    |
   +-------------------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0011__en-us_topic_0109852832_table15683233145412:

.. table:: **Table 8** **tags** parameter description

   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                                                              |
   +===========+========+==========================================================================================================================================================+
   | key       | String | Specifies the tag key. It contains a maximum of 127 Unicode characters and cannot be left blank. (This parameter is not verified in the search process.) |
   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+
   | value     | String | Specifies the tag value. Each tag value can contain a maximum of 255 Unicode characters.                                                                 |
   +-----------+--------+----------------------------------------------------------------------------------------------------------------------------------------------------------+

Example Request
---------------

-  Example request 1 (when **action** is set to **filter**)

   .. code-block:: text

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/resource_instances/action

      {
          "offset": "100",
          "limit": "100",
          "action": "filter",
          "matches": [
              {
                  "key": "resource_name",
                  "value": "resource1"
              }
          ],
          "tags": [
              {
                  "key": "key1",
                  "values": [
                      "value1",
                      "value2"
                  ]
              }
          ]
      }

-  Example request 2 (when **action** is set to **count**)

   .. code-block:: text

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/resource_instances/action

      {
          "action": "count",
          "tags": [
              {
                  "key": "key1",
                  "values": [
                      "value1",
                      "value2"
                  ]
              },
              {
                  "key": "key2",
                  "values": [
                      "value1",
                      "value2"
                  ]
              }
          ],
          "matches": [
              {
                  "key": "resource_name",
                  "value": "resource1"
              }
          ]
      }

Example Response
----------------

-  Example response 1

   .. code-block::

      {
          "resources": [
              {
                  "resource_detail":"",
                  "resource_id": "154d135b-3a89-4e89-8023-06efb9acdc05",
                  "resource_name": "resouece1",
                  "tags": [
                      {
                          "key": "key1",
                          "value": "value1"
                      },
                      {
                          "key": "key2",
                          "value": "value1"
                      }
                  ]
              }
          ],
          "total_count": 1000
      }

-  Example response 2

   .. code-block::

      {
          "total_count": 1000
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_zq_bq_0013>`.

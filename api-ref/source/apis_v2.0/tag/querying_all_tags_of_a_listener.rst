:original_name: elb_zq_bq_0009.html

.. _elb_zq_bq_0009:

Querying All Tags of a Listener
===============================

Function
--------

This API is used to query all tags of one listener.

.. note::

   You can also use this API for dedicated load balancers.

Constraints
-----------

None

URI
---

GET /v2.0/{project_id}/listeners/{listener_id}/tags

.. table:: **Table 1** Parameter description

   +-------------+-----------+--------+----------------------------------------------------------------+
   | Parameter   | Mandatory | Type   | Description                                                    |
   +=============+===========+========+================================================================+
   | project_id  | Yes       | String | Specifies the ID of the project where the tag is used.         |
   +-------------+-----------+--------+----------------------------------------------------------------+
   | listener_id | Yes       | String | Specifies the ID of the listener whose tags are to be queried. |
   +-------------+-----------+--------+----------------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ===========
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========
   X-Auth-Token Yes       String User token
   ============ ========= ====== ===========

Response Parameters
-------------------

.. table:: **Table 3** Response parameters

   +-----------+-------+--------------------------------------------------------------------------------------------------------------+
   | Parameter | Type  | Description                                                                                                  |
   +===========+=======+==============================================================================================================+
   | tags      | Array | Lists the tags. For details, see :ref:`Table 4 <elb_zq_bq_0009__en-us_topic_0112614717_table9829182310517>`. |
   +-----------+-------+--------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0009__en-us_topic_0112614717_table9829182310517:

.. table:: **Table 4** **tags** parameter description

   +-----------------------+-----------------------+---------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                         |
   +=======================+=======================+=====================================================================+
   | key                   | String                | Specifies the tag key.                                              |
   |                       |                       |                                                                     |
   |                       |                       | -  Cannot be left blank.                                            |
   |                       |                       | -  Can contain a maximum of 128 characters.                         |
   |                       |                       | -  Can contain only the following character types:                  |
   |                       |                       |                                                                     |
   |                       |                       |    -  Uppercase letters                                             |
   |                       |                       |    -  Lowercase letters                                             |
   |                       |                       |    -  Digits                                                        |
   |                       |                       |    -  Special characters, including hyphens (-) and underscores (_) |
   |                       |                       |                                                                     |
   |                       |                       | -  The tag key of a listener must be unique.                        |
   +-----------------------+-----------------------+---------------------------------------------------------------------+
   | value                 | String                | Specifies the tag value.                                            |
   |                       |                       |                                                                     |
   |                       |                       | -  Can contain a maximum of 255 characters.                         |
   |                       |                       | -  Can contain only the following character types:                  |
   |                       |                       |                                                                     |
   |                       |                       |    -  Uppercase letters                                             |
   |                       |                       |    -  Lowercase letters                                             |
   |                       |                       |    -  Digits                                                        |
   |                       |                       |    -  Special characters, including hyphens (-) and underscores (_) |
   +-----------------------+-----------------------+---------------------------------------------------------------------+

Example Request
---------------

-  Example request

   .. code-block:: text

      GET https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags

Example Response
----------------

-  Example response

   .. code-block::

      {
          "tags": [
              {
                  "key": "key1",
                  "value": "value1"
              },
              {
                  "key": "key2",
                  "value": "value2"
              }
          ]
      }

Status Code
-----------

For details, see :ref:`Status Codes <elb_zq_bq_0013>`.

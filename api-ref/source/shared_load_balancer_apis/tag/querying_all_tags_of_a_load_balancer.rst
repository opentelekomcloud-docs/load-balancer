:original_name: elb_zq_bq_0003.html

.. _elb_zq_bq_0003:

Querying All Tags of a Load Balancer
====================================

Function
--------

This API is used to query all the tags of one load balancer.

.. note::

   You can also use this API for dedicated load balancers.

URI
---

GET /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags

.. table:: **Table 1** Parameter description

   +-----------------+-----------+--------+---------------------------------------------------------------------+
   | Parameter       | Mandatory | Type   | Description                                                         |
   +=================+===========+========+=====================================================================+
   | project_id      | Yes       | String | Specifies the ID of the project where the tag is used.              |
   +-----------------+-----------+--------+---------------------------------------------------------------------+
   | loadbalancer_id | Yes       | String | Specifies the ID of the load balancer whose tags are to be queried. |
   +-----------------+-----------+--------+---------------------------------------------------------------------+

Request
-------

None

Response
--------

.. table:: **Table 2** Response parameters

   +-----------+-------+--------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type  | Description                                                                                                                          |
   +===========+=======+======================================================================================================================================+
   | tags      | Array | Lists the tags. For details, see :ref:`Table 3 <elb_zq_bq_0003__en-us_topic_0109852826_en-us_topic_0094115924_table57471170114349>`. |
   +-----------+-------+--------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0003__en-us_topic_0109852826_en-us_topic_0094115924_table57471170114349:

.. table:: **Table 3** **tags** parameter description

   +-----------------------+-----------------------+---------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                         |
   +=======================+=======================+=====================================================================+
   | key                   | String                | Specifies the tag key.                                              |
   |                       |                       |                                                                     |
   |                       |                       | -  Cannot be left blank.                                            |
   |                       |                       | -  Can contain a maximum of 36 characters.                          |
   |                       |                       | -  Can contain only the following character types:                  |
   |                       |                       |                                                                     |
   |                       |                       |    -  Uppercase letters                                             |
   |                       |                       |    -  Lowercase letters                                             |
   |                       |                       |    -  Digits                                                        |
   |                       |                       |    -  Special characters, including hyphens (-) and underscores (_) |
   |                       |                       |                                                                     |
   |                       |                       | -  The tag key of a load balancer must be unique.                   |
   +-----------------------+-----------------------+---------------------------------------------------------------------+
   | value                 | String                | Specifies the tag value.                                            |
   |                       |                       |                                                                     |
   |                       |                       | -  Can contain a maximum of 43 characters.                          |
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

      GET https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags

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

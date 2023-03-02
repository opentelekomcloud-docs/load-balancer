:original_name: elb_zq_bq_0007.html

.. _elb_zq_bq_0007:

Adding a Tag to a Listener
==========================

Function
--------

This API is used to add a tag to a specific listener.

.. note::

   You can also use this API for dedicated load balancers.

Constraints
-----------

-  A maximum of 20 tags can be added to a load balancer.
-  Note the following when you add tags:

   -  If there are duplicate keys in the request body, an error is reported.
   -  If there are no duplicate keys in the request body but the key in the request body exists in the database, the key in the database is overwritten.

URI
---

POST /v2.0/{project_id}/listeners/{listener_id}/tags

.. table:: **Table 1** Parameter description

   +-------------+-----------+--------+-----------------------------------------------------------------+
   | Parameter   | Mandatory | Type   | Description                                                     |
   +=============+===========+========+=================================================================+
   | project_id  | Yes       | String | Specifies the ID of the project where the tag is used.          |
   +-------------+-----------+--------+-----------------------------------------------------------------+
   | listener_id | Yes       | String | Specifies the ID of the listener to which a tag is to be added. |
   +-------------+-----------+--------+-----------------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ===========
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========
   X-Auth-Token Yes       String User token
   ============ ========= ====== ===========

.. table:: **Table 3** Parameter description

   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                     |
   +===========+===========+========+=================================================================================================================+
   | tag       | Yes       | Object | Specifies the tag. For details, see :ref:`Table 4 <elb_zq_bq_0007__en-us_topic_0112614719_table1537216133220>`. |
   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0007__en-us_topic_0112614719_table1537216133220:

.. table:: **Table 4** **tag** parameter description

   +-----------------+-----------------+-----------------+---------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                         |
   +=================+=================+=================+=====================================================================+
   | key             | Yes             | String          | Specifies the tag key.                                              |
   |                 |                 |                 |                                                                     |
   |                 |                 |                 | -  Cannot be left blank.                                            |
   |                 |                 |                 | -  Can contain a maximum of 36 characters.                          |
   |                 |                 |                 | -  Can contain only the following character types:                  |
   |                 |                 |                 |                                                                     |
   |                 |                 |                 |    -  Uppercase letters                                             |
   |                 |                 |                 |    -  Lowercase letters                                             |
   |                 |                 |                 |    -  Digits                                                        |
   |                 |                 |                 |    -  Special characters, including hyphens (-) and underscores (_) |
   |                 |                 |                 |                                                                     |
   |                 |                 |                 | -  The tag key of a listener must be unique.                        |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------+
   | value           | Yes             | String          | Specifies the tag value.                                            |
   |                 |                 |                 |                                                                     |
   |                 |                 |                 | -  Can contain a maximum of 43 characters.                          |
   |                 |                 |                 | -  Can contain only the following character types:                  |
   |                 |                 |                 |                                                                     |
   |                 |                 |                 |    -  Uppercase letters                                             |
   |                 |                 |                 |    -  Lowercase letters                                             |
   |                 |                 |                 |    -  Digits                                                        |
   |                 |                 |                 |    -  Special characters, including hyphens (-) and underscores (_) |
   +-----------------+-----------------+-----------------+---------------------------------------------------------------------+

Response Parameters
-------------------

None

Example Request
---------------

-  Example request

   .. code-block:: text

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags

      {
          "tag": {
              "key": "key1",
              "value": "value1"
          }
      }

Example Response
----------------

-  Example response

   None

Status Code
-----------

For details, see :ref:`Status Codes <elb_zq_bq_0013>`.

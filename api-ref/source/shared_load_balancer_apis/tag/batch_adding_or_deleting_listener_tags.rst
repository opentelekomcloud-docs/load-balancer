:original_name: elb_zq_bq_0008.html

.. _elb_zq_bq_0008:

Batch Adding or Deleting Listener Tags
======================================

Function
--------

This API is used to batch add tags to or delete tags from a listener.

.. note::

   You can also use this API for dedicated load balancers.

Constraints
-----------

-  A maximum of 20 tags can be added to a listener.
-  This API is idempotent.
-  Note the following when you add tags:

   -  If there are duplicate keys in the request body, an error is reported.
   -  If there are no duplicate keys in the request body but the key in the request body exists in the database, the key in the database is overwritten.

-  Note the following when you delete the tags:

   -  If the tag to be deleted does not exist, the deletion is considered successful by default.
   -  The value range of the tag character set is not verified.
   -  The tag structure body cannot be missing, and the key cannot be left blank or set to an empty string.

URI
---

POST /v2.0/{project_id}/listeners/{listener_id}/tags/action

.. table:: **Table 1** Parameter description

   +-------------+-----------+--------+------------------------------------------------------------------------------------------------------+
   | Parameter   | Mandatory | Type   | Description                                                                                          |
   +=============+===========+========+======================================================================================================+
   | project_id  | Yes       | String | Specifies the ID of the project where the tag is used.                                               |
   +-------------+-----------+--------+------------------------------------------------------------------------------------------------------+
   | listener_id | Yes       | String | Specifies the ID of the listener to which tags are to be added or from which tags are to be deleted. |
   +-------------+-----------+--------+------------------------------------------------------------------------------------------------------+

Request
-------

.. table:: **Table 2** Parameter description

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                          |
   +=================+=================+=================+======================================================================================================================================+
   | tags            | Yes             | Array           | Lists the tags. For details, see :ref:`Table 3 <elb_zq_bq_0008__en-us_topic_0109852833_en-us_topic_0094115927_table27826557114623>`. |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------+
   | action          | Yes             | String          | Specifies the operation identifier.                                                                                                  |
   |                 |                 |                 |                                                                                                                                      |
   |                 |                 |                 | The value can be one of the following:                                                                                               |
   |                 |                 |                 |                                                                                                                                      |
   |                 |                 |                 | -  **create**: adds tags to the listener.                                                                                            |
   |                 |                 |                 | -  **delete**: deletes tags from the listener.                                                                                       |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bq_0008__en-us_topic_0109852833_en-us_topic_0094115927_table27826557114623:

.. table:: **Table 3** **resource_tag** parameter description

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

Response
--------

None

Example Request
---------------

-  Example request 1

   .. code-block:: text

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags/action

      {
          "action": "create",
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

-  Example request 2

   .. code-block:: text

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags/action

      {
          "action": "delete",
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

Example Response
----------------

-  Example response 1

   None

-  Example response 2

   None

Status Code
-----------

For details, see :ref:`Status Codes <elb_zq_bq_0013>`.

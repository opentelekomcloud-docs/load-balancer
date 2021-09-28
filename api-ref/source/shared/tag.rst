===
Tag
===

Adding a Tag to a Load Balancer
===============================

Function
^^^^^^^^

This API is used to add a tag to a specific load balancer for easier management.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

A maximum of 20 tags can be added to a load balancer.

Note the following when you add tags:

-  If there are duplicate keys in the request body, an error is reported.  -
   If there are no duplicate keys in the request body but the key in the
   request body exists in the database, the key in the database is overwritten.

URI
^^^

POST /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags

.. table:: **Table 1** Parameter description

   =============== ============= ======== ====================================================================
   Parameter       **Mandatory** **Type** Description
   =============== ============= ======== ====================================================================
   project_id      Yes           String   Specifies the ID of the project where the tag is used.
   loadbalancer_id Yes           String   Specifies the ID of the load balancer to which a tag is to be added.
   =============== ============= ======== ====================================================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-----------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                         |
   +===========+===========+========+=====================================================+
   | tag       | Yes       | Object | Specifies the tag. For details, see :ref:`stlc_t3`. |
   +-----------+-----------+--------+-----------------------------------------------------+

.. _stlc_t3:
.. table:: **Table 3** **tag** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key.      |
   |           |           |        |                             |
   |           |           |        | -  Cannot be left blank.    |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    36 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   |           |           |        |                             |
   |           |           |        | -  The tag key of a load    |
   |           |           |        |    balancer must be unique. |
   +-----------+-----------+--------+-----------------------------+
   | value     | Yes       | String | Specifies the tag value.    |
   |           |           |        |                             |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    43 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags

      {
          "tag": {
              "key": "key1",
              "value": "value1"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Batch Adding or Deleting Load Balancer Tags
===========================================

Function
^^^^^^^^

This API is used to batch add tags to or delete tags from a load balancer.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

A maximum of 20 tags can be added to a load balancer.

This API is idempotent.

-  Note the following when you add tags:

   -  If there are duplicate keys in the request body, an error is reported.  -
      If there are no duplicate keys in the request body but the key in the
      request body exists in the database, the key in the database is
      overwritten.

-  Note the following when you delete the tags:

   -  If the tag to be deleted does not exist, the deletion is considered
      successful by default.  -  The value range of the tag character set is
      not verified.  -  The tag structure body cannot be missing, and the key
      cannot be left blank or set to an empty string.

URI
^^^

POST /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags/action

.. table:: **Table 1** Parameter description

   +-----------------+-----------+--------+---------------------------------------------------------------------+
   | Parameter       | Mandatory | Type   | Description                                                         |
   +=================+===========+========+=====================================================================+
   | project_id      | Yes       | String | Specifies the ID of the project where the tag is used.              |
   +-----------------+-----------+--------+---------------------------------------------------------------------+
   | loadbalancer_id | Yes       | String | Specifies the ID of the load balancer to which tags are to be added |
   |                 |           |        | or from which tags are to be deleted.                               |
   +-----------------+-----------+--------+---------------------------------------------------------------------+

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+------------------------------+
   | Parameter | Mandatory | Type   | Description                  |
   +===========+===========+========+==============================+
   | tags      | Yes       | Array  | Lists the tags. For          |
   |           |           |        | details, see :ref:`stlb_t3`. |
   +-----------+-----------+--------+------------------------------+
   | action    | Yes       | String | Specifies the operation      |
   |           |           |        | type.                        |
   |           |           |        |                              |
   |           |           |        | The value can be one of the  |
   |           |           |        | following:                   |
   |           |           |        |                              |
   |           |           |        | -  **create**: adds tags to  |
   |           |           |        |    the load balancer.        |
   |           |           |        | -  **delete**: deletes tags  |
   |           |           |        |    from the load balancer.   |
   +-----------+-----------+--------+------------------------------+

.. _stlb_t3:
.. table:: **Table 3** **tags** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key.      |
   |           |           |        |                             |
   |           |           |        | -  Cannot be left blank.    |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    36 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   |           |           |        |                             |
   |           |           |        | -  The tag key of a load    |
   |           |           |        |    balancer must be unique. |
   +-----------+-----------+--------+-----------------------------+
   | value     | Yes       | String | Specifies the tag value.    |
   |           |           |        |                             |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    43 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request 1

   .. code::

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags/action

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

   .. code::

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags/action

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
^^^^^^^^^^^^^^^^

-  Example response 1

   None

-  Example response 2

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying All Tags of a Load Balancer
====================================

Function
^^^^^^^^

This API is used to query all the tags of one load balancer.

|image1|

You can also use this API for dedicated load balancers.

URI
^^^

GET /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===================================================================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===================================================================
   project_id      Yes       String Specifies the ID of the project where the tag is used.
   loadbalancer_id Yes       String Specifies the ID of the load balancer whose tags are to be queried.
   =============== ========= ====== ===================================================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+-------+-------------------------------------------------+
   | Parameter | Type  | Description                                     |
   +===========+=======+=================================================+
   | tags      | Array | Lists the tags. For details, see :ref:`stl_t3`. |
   +-----------+-------+-------------------------------------------------+

.. _stl_t3:
.. table:: **Table 3** **tags** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | key       | String | Specifies the tag key.                |
   |           |        |                                       |
   |           |        | -  Cannot be left blank.              |
   |           |        | -  Can contain a maximum of 36        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   |           |        |                                       |
   |           |        | -  The tag key of a load balancer     |
   |           |        |    must be unique.                    |
   +-----------+--------+---------------------------------------+
   | value     | String | Specifies the tag value.              |
   |           |        |                                       |
   |           |        | -  Can contain a maximum of 43        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      GET https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying the Tags of All Load Balancers
=======================================

Function
^^^^^^^^

This API is used to query the tags of all the load balancers.

|image1|

You can also use this API for dedicated load balancers.

URI
^^^

GET /v2.0/{project_id}/loadbalancers/tags

.. table:: **Table 1** Parameter description

   ========== ========= ====== ======================================================
   Parameter  Mandatory Type   Description
   ========== ========= ====== ======================================================
   project_id Yes       String Specifies the ID of the project where the tag is used.
   ========== ========= ====== ======================================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+-------+--------------------------------------------------+
   | Parameter | Type  | Description                                      |
   +===========+=======+==================================================+
   | tags      | Array | Lists the tags. For details, see :ref:`stla_t3`. |
   +-----------+-------+--------------------------------------------------+

.. _stla_t3:
.. table:: **Table 3** **tags** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | key       | String | Specifies the tag key.                |
   |           |        |                                       |
   |           |        | -  Cannot be left blank.              |
   |           |        | -  Can contain a maximum of 36        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   |           |        |                                       |
   |           |        | -  The tag key of a load balancer     |
   |           |        |    must be unique.                    |
   +-----------+--------+---------------------------------------+
   | values    | Array  | Lists the tag values.                 |
   |           |        |                                       |
   |           |        | -  Can contain a maximum of 43        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      GET https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/tags

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
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
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Load Balancers by Tag
==============================

Function
^^^^^^^^

This API is used to query load balancers using tags.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

None

URI
^^^

POST /v2.0/{project_id}/loadbalancers/resource_instances/action

.. table:: **Table 1** Parameter description

   ========== ============= ======== ======================================================
   Parameter  Mandatory     Type     Description
   ========== ============= ======== ======================================================
   project_id Yes           String   Specifies the ID of the project where the tag is used.
   ========== ============= ======== ======================================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+---------+------------------------------+
   | Parameter | Mandatory | Type    | Description                  |
   +===========+===========+=========+==============================+
   | tags      | No        | Array   | Specifies the included       |
   |           |           |         | tags. A maximum of 20 keys   |
   |           |           |         | are allowed for each query   |
   |           |           |         | operation, and each key can  |
   |           |           |         | have a maximum of 20         |
   |           |           |         | values.                      |
   |           |           |         |                              |
   |           |           |         | The tag key cannot be left   |
   |           |           |         | blank or set to an empty     |
   |           |           |         | string.                      |
   |           |           |         |                              |
   |           |           |         | Each tag key and each tag    |
   |           |           |         | value of the same tag key    |
   |           |           |         | must be unique.              |
   +-----------+-----------+---------+------------------------------+
   | limit     | No        | Integer | Sets the page size. This     |
   |           |           |         | parameter is available when  |
   |           |           |         | **action** is set to         |
   |           |           |         | **filter**. Both the         |
   |           |           |         | default value and maximum    |
   |           |           |         | value are **1000**, and the  |
   |           |           |         | minimum value is **1**. The  |
   |           |           |         | value cannot be a negative   |
   |           |           |         | integer.                     |
   +-----------+-----------+---------+------------------------------+
   | offset    | No        | Integer | Specifies the index          |
   |           |           |         | position. The query starts   |
   |           |           |         | from the next load balancer  |
   |           |           |         | indexed by this parameter.   |
   |           |           |         | This parameter is not        |
   |           |           |         | required when you query      |
   |           |           |         | load balancers on the first  |
   |           |           |         | page. The value in the       |
   |           |           |         | response returned for        |
   |           |           |         | querying the load balancers  |
   |           |           |         | on the previous page will    |
   |           |           |         | be included in this          |
   |           |           |         | parameter for querying the   |
   |           |           |         | load balancers on            |
   |           |           |         | subsequent pages. This       |
   |           |           |         | parameter is not available   |
   |           |           |         | when **action** is set to    |
   |           |           |         | **count**. If **action** is  |
   |           |           |         | set to **filter**, the       |
   |           |           |         | value must be a positive     |
   |           |           |         | integer, and the default     |
   |           |           |         | value is **0**.              |
   +-----------+-----------+---------+------------------------------+
   | action    | Yes       | String  | Identifies the operation.    |
   |           |           |         | The value can be **filter**  |
   |           |           |         | or **count**.                |
   |           |           |         |                              |
   |           |           |         | **filter**: indicates        |
   |           |           |         | pagination query.            |
   |           |           |         |                              |
   |           |           |         | **count**: indicates that    |
   |           |           |         | all load balancers meeting   |
   |           |           |         | the search criteria will be  |
   |           |           |         | returned.                    |
   +-----------+-----------+---------+------------------------------+
   | matches   | No        | Array   | Specifies the search         |
   |           |           |         | criteria. The tag key is     |
   |           |           |         | the parameter to match, for  |
   |           |           |         | example, **resource_name**.  |
   |           |           |         | **value** indicates the      |
   |           |           |         | value of the match content.  |
   |           |           |         | The key is a fixed           |
   |           |           |         | dictionary value.            |
   |           |           |         |                              |
   |           |           |         | Currently, only              |
   |           |           |         | **resource_name** can be     |
   |           |           |         | used for search. For         |
   |           |           |         | details, see :ref:`stlb_t4`. |
   +-----------+-----------+---------+------------------------------+

.. table:: **Table 3** **tags** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key. It   |
   |           |           |        | contains a maximum of 127   |
   |           |           |        | Unicode characters and      |
   |           |           |        | cannot be left blank. (This |
   |           |           |        | parameter is not verified   |
   |           |           |        | in the search process.)     |
   +-----------+-----------+--------+-----------------------------+
   | values    | Yes       | Array  | Lists the tag values. Each  |
   |           |           |        | tag value can contain a     |
   |           |           |        | maximum of 255 Unicode      |
   |           |           |        | characters. The values are  |
   |           |           |        | in the OR relationship.     |
   |           |           |        |                             |
   |           |           |        | If no tag values in the     |
   |           |           |        | list, the tag key is used   |
   |           |           |        | for full search. If each    |
   |           |           |        | value in the list starts    |
   |           |           |        | with an asterisk (*), fuzzy |
   |           |           |        | match is performed based on |
   |           |           |        | the part after the          |
   |           |           |        | asterisk.                   |
   +-----------+-----------+--------+-----------------------------+

.. _stlb_t4:
.. table:: **Table 4** **matches** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key for   |
   |           |           |        | match.                      |
   |           |           |        |                             |
   |           |           |        | The value can be one of the |
   |           |           |        | following:                  |
   |           |           |        |                             |
   |           |           |        | -  **resource_name**:       |
   |           |           |        |    indicates the resource   |
   |           |           |        |    name.                    |
   +-----------+-----------+--------+-----------------------------+
   | value     | Yes       | String | Specifies the tag value for |
   |           |           |        | match. Each tag value can   |
   |           |           |        | contain a maximum of 255    |
   |           |           |        | Unicode characters.         |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 5** Response parameters

   +-------------+---------+------------------------------------------------------------+
   | Parameter   | Type    | Description                                                |
   +=============+=========+============================================================+
   | resources   | Array   | Lists the load balancers. For details, see :ref:`stlb_t6`. |
   +-------------+---------+------------------------------------------------------------+
   | total_count | Integer | Specifies the total number of queried records.             |
   +-------------+---------+------------------------------------------------------------+

.. _stlb_t6:
.. table:: **Table 6** **resource** parameter description

   +-------------------+--------+-------------------------------------------------------------------------------------+
   | Parameter         | Type   | Description                                                                         |
   +===================+========+=====================================================================================+
   | resource_id       | String | Specifies the resource ID.                                                          |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | resource_detail   | Object | Specifies the resource details. The value is a resource object, used for extension. |
   |                   |        | The value is left blank by default.                                                 |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | tags              | Array  | Lists the tags. If there is no tag, an empty array is used by default. For details, |
   |                   |        | see :ref:`stlb_t7`.                                                                 |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | resource_name     | String | Specifies the resource name. This parameter is an empty string by default if there  |
   |                   |        | is no resource name.                                                                |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | super_resource_id | String | Specifies the parent resource ID.                                                   |
   +-------------------+--------+-------------------------------------------------------------------------------------+

.. _stlb_t7:
.. table:: **Table 7** **tags** parameter description

   +-----------+--------+-------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                               |
   +===========+========+===========================================================================================+
   | key       | String | Specifies the tag key. It contains a maximum of 127 Unicode characters and cannot be left |
   |           |        | blank. (This parameter is not verified in the search process.)                            |
   +-----------+--------+-------------------------------------------------------------------------------------------+
   | value     | String | Specifies the tag value. Each tag value can contain a maximum of 255 Unicode characters.  |
   +-----------+--------+-------------------------------------------------------------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1 (when **action** is set to **filter**)

   .. code::

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/resource_instances/action

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
                      "*value1",
                      "value2"
                  ]
              }
          ]
      }

-  Example request 2 (when **action** is set to **count**)

   .. code::

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/resource_instances/action

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
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "resources": [
              {
                  "resource_detail": "",
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

   .. code::

      {
          "total_count": 1000
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Tag from a Load Balancer
===================================

Function
^^^^^^^^

This API is used to delete a tag with a specific key from a load balancer.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

None

URI
^^^

DELETE /v2.0/{project_id}/loadbalancers/{loadbalancer_id}/tags/{key}

.. table:: **Table 1** Parameter description

   =============== ============= ======== ========================================================================
   Parameter       Mandatory     Type     Description
   =============== ============= ======== ========================================================================
   project_id      Yes           String   Specifies the ID of the project where the tag is used.
   loadbalancer_id Yes           String   Specifies the ID of the load balancer from which a tag is to be deleted.
   =============== ============= ======== ========================================================================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      DELETE https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/loadbalancers/7add33ad-11dc-4ab9-a50f-419703f13163/tags/key1

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Adding a Tag to a Listener
==========================

Function
^^^^^^^^

This API is used to add a tag to a specific listener.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

-  A maximum of 20 tags can be added to a listener.  -  Note the following when
   you add tags:

   -  If there are duplicate keys in the request body, an error is reported.  -
      If there are no duplicate keys in the request body but the key in the
      request body exists in the database, the key in the database is
      overwritten.

URI
^^^

POST /v2.0/{project_id}/listeners/{listener_id}/tags

.. table:: **Table 1** Parameter description

   =========== ============= ======== ===============================================================
   Parameter   Mandatory     Type     Description
   =========== ============= ======== ===============================================================
   project_id  Yes           String   Specifies the ID of the project where the tag is used.
   listener_id Yes           String   Specifies the ID of the listener to which a tag is to be added.
   =========== ============= ======== ===============================================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                        |
   +===========+===========+========+====================================================================+
   | tag       | Yes       | Object | Specifies the tag. For details, see :ref:`stlic_t3`.               |
   +-----------+-----------+--------+--------------------------------------------------------------------+

.. _stlic_t3:
.. table:: **Table 3** **tag** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key.      |
   |           |           |        |                             |
   |           |           |        | -  Cannot be left blank.    |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    36 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   |           |           |        |                             |
   |           |           |        | -  The tag key of a         |
   |           |           |        |    listener must be unique. |
   +-----------+-----------+--------+-----------------------------+
   | value     | Yes       | String | Specifies the tag value.    |
   |           |           |        |                             |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    43 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      POST https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags

      {
          "tag": {
              "key": "key1",
              "value": "value1"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Batch Adding or Deleting Listener Tags
======================================

Function
^^^^^^^^

This API is used to batch add tags to or delete tags from a listener.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

- A maximum of 20 tags can be added to a listener.
- This API is idempotent.
- Note the following when you add tags:

  - If there are duplicate keys in the request body, an error is reported.
  - If there are no duplicate keys in the request body but the key in the
    request body exists in the database, the key in the database is
    overwritten.

- Note the following when you delete the tags:

  - If the tag to be deleted does not exist, the deletion is considered
    successful by default.
  - The value range of the tag character set is not verified.
  - The tag structure body cannot be missing, and the key cannot be left blank
    or set to an empty string.

URI
^^^

POST /v2.0/{project_id}/listeners/{listener_id}/tags/action

.. table:: **Table 1** Parameter description

   +-------------+-----------+--------+------------------------------------------------------------------------+
   | Parameter   | Mandatory | Type   | Description                                                            |
   +=============+===========+========+========================================================================+
   | project_id  | Yes       | String | Specifies the ID of the project where the tag is used.                 |
   +-------------+-----------+--------+------------------------------------------------------------------------+
   | listener_id | Yes       | String | Specifies the ID of the listener to which tags are to be added or from |
   |             |           |        | which tags are to be deleted.                                          |
   +-------------+-----------+--------+------------------------------------------------------------------------+

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-------------------------------+
   | Parameter | Mandatory | Type   | Description                   |
   +===========+===========+========+===============================+
   | tags      | Yes       | Array  | Lists the tags. For           |
   |           |           |        | details, see :ref:`stlib_t3`. |
   +-----------+-----------+--------+-------------------------------+
   | action    | Yes       | String | Specifies the operation       |
   |           |           |        | identifier.                   |
   |           |           |        |                               |
   |           |           |        | The value can be one of the   |
   |           |           |        | following:                    |
   |           |           |        |                               |
   |           |           |        | -  **create**: adds tags to   |
   |           |           |        |    the listener.              |
   |           |           |        | -  **delete**: deletes tags   |
   |           |           |        |    from the listener.         |
   +-----------+-----------+--------+-------------------------------+

.. _stlib_t3:
.. table:: **Table 3** **resource_tag** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key.      |
   |           |           |        |                             |
   |           |           |        | -  Cannot be left blank.    |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    36 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   |           |           |        |                             |
   |           |           |        | -  The tag key of a         |
   |           |           |        |    listener must be unique. |
   +-----------+-----------+--------+-----------------------------+
   | value     | Yes       | String | Specifies the tag value.    |
   |           |           |        |                             |
   |           |           |        | -  Can contain a maximum of |
   |           |           |        |    43 characters.           |
   |           |           |        | -  Can contain only the     |
   |           |           |        |    following character      |
   |           |           |        |    types:                   |
   |           |           |        |                             |
   |           |           |        |    -  Uppercase letters     |
   |           |           |        |    -  Lowercase letters     |
   |           |           |        |    -  Digits                |
   |           |           |        |    -  Special characters,   |
   |           |           |        |       including hyphens (-) |
   |           |           |        |       and underscores (_)   |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request 1

   .. code::

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

   .. code::

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
^^^^^^^^^^^^^^^^

-  Example response 1

   None

-  Example response 2

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying All Tags of a Listener
===============================

Function
^^^^^^^^

This API is used to query all tags of one listener.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

None

URI
^^^

GET /v2.0/{project_id}/listeners/{listener_id}/tags

.. table:: **Table 1** Parameter description

   =========== ============= ======== ==============================================================
   Parameter   Mandatory     Type     Description
   =========== ============= ======== ==============================================================
   project_id  Yes           String   Specifies the ID of the project where the tag is used.
   listener_id Yes           String   Specifies the ID of the listener whose tags are to be queried.
   =========== ============= ======== ==============================================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+----------+--------------------------------------------------------------------+
   | Parameter | **Type** | Description                                                        |
   +===========+==========+====================================================================+
   | tags      | Array    | Lists the tags. For details, see :ref:`stlila_t3`.                 |
   +-----------+----------+--------------------------------------------------------------------+

.. _stlila_t3:
.. table:: **Table 3** **tags** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | key       | String | Specifies the tag key.                |
   |           |        |                                       |
   |           |        | -  Cannot be left blank.              |
   |           |        | -  Can contain a maximum of 36        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   |           |        |                                       |
   |           |        | -  The tag key of a listener must be  |
   |           |        |    unique.                            |
   +-----------+--------+---------------------------------------+
   | value     | String | Specifies the tag value.              |
   |           |        |                                       |
   |           |        | -  Can contain a maximum of 43        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      GET https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

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
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying the Tags of All Listeners
==================================

Function
^^^^^^^^

This API is used to query the tags of all listeners.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

None

URI
^^^

GET /v2.0/{project_id}/listeners/tags

.. table:: **Table 1** Parameter description

   ========== ============= ======== ======================================================
   Parameter  Mandatory     Type     Description
   ========== ============= ======== ======================================================
   project_id Yes           String   Specifies the ID of the project where the tag is used.
   ========== ============= ======== ======================================================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+-------+---------------------------------------+
   | Parameter | Type  | Description                           |
   +===========+=======+=======================================+
   | tags      | Array | Lists the tags, which are aggregated  |
   |           |       | by the tag key. For details, see      |
   |           |       | :ref:`stlilat_t3`.                    |
   |           |       |                                       |
   |           |       | For example, if you have two          |
   |           |       | listeners, the tag key of both        |
   |           |       | listeners is "test", the tag value of |
   |           |       | listener A is "value1", and the tag   |
   |           |       | value of listener B is "value2", two  |
   |           |       | tags are queried, the key of both     |
   |           |       | tags is "test", and the tag values    |
   |           |       | are ["value1","value2"].              |
   +-----------+-------+---------------------------------------+

.. _stlilat_t3:
.. table:: **Table 3** **tags** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | key       | String | Specifies the tag key.                |
   |           |        |                                       |
   |           |        | -  Cannot be left blank.              |
   |           |        | -  Can contain a maximum of 36        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   |           |        |                                       |
   |           |        | -  The tag key of a listener must be  |
   |           |        |    unique.                            |
   +-----------+--------+---------------------------------------+
   | values    | Array  | Lists the tag values.                 |
   |           |        |                                       |
   |           |        | -  Can contain a maximum of 43        |
   |           |        |    characters.                        |
   |           |        | -  Can contain only the following     |
   |           |        |    character types:                   |
   |           |        |                                       |
   |           |        |    -  Uppercase letters               |
   |           |        |    -  Lowercase letters               |
   |           |        |    -  Digits                          |
   |           |        |    -  Special characters, including   |
   |           |        |       hyphens (-) and underscores (_) |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      GET https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/tags

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
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
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Listeners by Tag
=========================

Function
^^^^^^^^

This API is used to query listeners by tag.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

None

URI
^^^

POST /v2.0/{project_id}/listeners/resource_instances/action

.. table:: **Table 1** Parameter description

   ========== ============= ======== ======================================================
   Parameter  Mandatory     Type     Description
   ========== ============= ======== ======================================================
   project_id Yes           String   Specifies the ID of the project where the tag is used.
   ========== ============= ======== ======================================================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+---------+--------------------------------+
   | Parameter | Mandatory | Type    | Description                    |
   +===========+===========+=========+================================+
   | tags      | No        | Array   | Specifies the included         |
   |           |           |         | tags. A maximum of 20 tag      |
   |           |           |         | keys are allowed for each      |
   |           |           |         | query operation. Each tag      |
   |           |           |         | key can have up to 20 tag      |
   |           |           |         | values. The structure body     |
   |           |           |         | must be included. The tag      |
   |           |           |         | key cannot be left blank or    |
   |           |           |         | set to an empty string.        |
   |           |           |         | Each tag key and each tag      |
   |           |           |         | value of the same tag key      |
   |           |           |         | must be unique. For            |
   |           |           |         | details, see :ref:`stlita_t3`. |
   +-----------+-----------+---------+--------------------------------+
   | limit     | No        | Integer | Sets the page size. This       |
   |           |           |         | parameter is available when    |
   |           |           |         | **action** is set to           |
   |           |           |         | **filter**. Both the           |
   |           |           |         | default value and maximum      |
   |           |           |         | value are **1000**, and the    |
   |           |           |         | minimum value is **1**. The    |
   |           |           |         | value cannot be a negative     |
   |           |           |         | integer.                       |
   +-----------+-----------+---------+--------------------------------+
   | offset    | No        | Integer | Specifies the index            |
   |           |           |         | position. The query starts     |
   |           |           |         | from the next listener         |
   |           |           |         | indexed by this parameter.     |
   |           |           |         | This parameter is not          |
   |           |           |         | required when you query        |
   |           |           |         | listeners on the first         |
   |           |           |         | page. The value in the         |
   |           |           |         | response returned for          |
   |           |           |         | querying the listeners on      |
   |           |           |         | the previous page will be      |
   |           |           |         | included in this parameter     |
   |           |           |         | for querying the listeners     |
   |           |           |         | on subsequent pages. This      |
   |           |           |         | parameter is not available     |
   |           |           |         | when **action** is set to      |
   |           |           |         | **count**. If **action** is    |
   |           |           |         | set to **filter**, the         |
   |           |           |         | value must be a positive       |
   |           |           |         | integer, and the default       |
   |           |           |         | value is **0**.                |
   +-----------+-----------+---------+--------------------------------+
   | action    | Yes       | String  | Identifies the operation.      |
   |           |           |         | The value can be **filter**    |
   |           |           |         | or **count**.                  |
   |           |           |         |                                |
   |           |           |         | -  **filter**: indicates       |
   |           |           |         |    pagination query.           |
   |           |           |         | -  **count**: indicates        |
   |           |           |         |    that all listeners          |
   |           |           |         |    meeting the search          |
   |           |           |         |    criteria will be            |
   |           |           |         |    returned.                   |
   +-----------+-----------+---------+--------------------------------+
   | matches   | No        | Array   | Specifies the search           |
   |           |           |         | criteria. The tag key is       |
   |           |           |         | the parameter to match, for    |
   |           |           |         | example, **resource_name**.    |
   |           |           |         | **value** indicates the        |
   |           |           |         | value of the match content.    |
   |           |           |         | The key is a fixed             |
   |           |           |         | dictionary value.              |
   |           |           |         |                                |
   |           |           |         | Determine whether fuzzy        |
   |           |           |         | match is required based on     |
   |           |           |         | different parameters. For      |
   |           |           |         | example, if the **key** is     |
   |           |           |         | **resource_name**, fuzzy       |
   |           |           |         | search is used by default.     |
   |           |           |         | If **value** is an empty       |
   |           |           |         | string, exact match is         |
   |           |           |         | used. If the key is            |
   |           |           |         | **resource_id**, exact         |
   |           |           |         | match is used. Currently,      |
   |           |           |         | only **resource_name** can     |
   |           |           |         | be used for search. For        |
   |           |           |         | details, see :ref:`stlita_t4`. |
   +-----------+-----------+---------+--------------------------------+

.. _stlita_t3:
.. table:: **Table 3** **tags** parameter description

   +-----------+-----------+--------+----------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                |
   +===========+===========+========+============================================================================+
   | key       | Yes       | String | Specifies the tag key. It contains a maximum of 127 Unicode characters and |
   |           |           |        | cannot be left blank. (This parameter is not verified in the search        |
   |           |           |        | process.)                                                                  |
   +-----------+-----------+--------+----------------------------------------------------------------------------+
   | values    | Yes       | Array  | Lists the tag values. Each tag value can contain a maximum of 255 Unicode  |
   |           |           |        | characters. The values are in the OR relationship.                         |
   +-----------+-----------+--------+----------------------------------------------------------------------------+

.. _stlita_t4:
.. table:: **Table 4** **matches** parameter description

   +-----------+-----------+--------+-----------------------------+
   | Parameter | Mandatory | Type   | Description                 |
   +===========+===========+========+=============================+
   | key       | Yes       | String | Specifies the tag key.      |
   |           |           |        |                             |
   |           |           |        | The value can be one of the |
   |           |           |        | following:                  |
   |           |           |        |                             |
   |           |           |        | -  **resource_name**:       |
   |           |           |        |    indicates the resource   |
   |           |           |        |    name.                    |
   +-----------+-----------+--------+-----------------------------+
   | value     | Yes       | String | Specifies the tag value.    |
   |           |           |        | Each tag value can contain  |
   |           |           |        | a maximum of 255 Unicode    |
   |           |           |        | characters.                 |
   +-----------+-----------+--------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 5** Response parameters

   +-------------+---------+---------------------------------------------------------+
   | Parameter   | Type    | Description                                             |
   +=============+=========+=========================================================+
   | resources   | Array   | Lists the listeners. For details, see :ref:`stlita_t6`. |
   +-------------+---------+---------------------------------------------------------+
   | total_count | Integer | Specifies the total number of queried records.          |
   +-------------+---------+---------------------------------------------------------+

.. _stlita_t6:
.. table:: **Table 6** **resource** parameter description

   +-------------------+--------+-------------------------------------------------------------------------------------+
   | Parameter         | Type   | Description                                                                         |
   +===================+========+=====================================================================================+
   | resource_id       | String | Specifies the resource ID.                                                          |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | resource_detail   | Object | Specifies the resource details. The value is a resource object, used for extension. |
   |                   |        | The value is left blank by default.                                                 |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | tags              | Array  | Lists the tags. If there is no tag, an empty array is used by default. For details, |
   |                   |        | see :ref:`stlita_t7`.                                                               |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | resource_name     | String | Specifies the resource name. This parameter is an empty string by default if there  |
   |                   |        | is no resource name.                                                                |
   +-------------------+--------+-------------------------------------------------------------------------------------+
   | super_resource_id | String | Specifies the parent resource ID.                                                   |
   +-------------------+--------+-------------------------------------------------------------------------------------+

.. _stlita_t7:
.. table:: **Table 7** **tags** parameter description

   +-----------+--------+-------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                               |
   +===========+========+===========================================================================================+
   | key       | String | Specifies the tag key. It contains a maximum of 127 Unicode characters and cannot be left |
   |           |        | blank. (This parameter is not verified in the search process.)                            |
   +-----------+--------+-------------------------------------------------------------------------------------------+
   | value     | String | Specifies the tag value. Each tag value can contain a maximum of 255 Unicode characters.  |
   +-----------+--------+-------------------------------------------------------------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1 (when **action** is set to **filter**)

   .. code::

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

   .. code::

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
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

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

   .. code::

      {
          "total_count": 1000
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Tag from a Listener
==============================

Function
^^^^^^^^

This API is used to delete a tag with a specific key from a listener.

|image1|

You can also use this API for dedicated load balancers.

Constraints
^^^^^^^^^^^

None

URI
^^^

DELETE /v2.0/{project_id}/listeners/{listener_id}/tags/{key}

.. table:: **Table 1** Parameter description

   =========== ============= ======== ===================================================================
   Parameter   Mandatory     Type     Description
   =========== ============= ======== ===================================================================
   project_id  Yes           String   Specifies the ID of the project where the tag is used.
   listener_id Yes           String   Specifies the ID of the listener from which a tag is to be deleted.
   =========== ============= ======== ===================================================================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request

   .. code::

      DELETE https://{Endpoint}/v2.0/6a0de1c3-7d74-4f4a-b75e-e57135bd2b97/listeners/7add33ad-11dc-4ab9-a50f-419703f13163/tags/key1

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.


.. |image1| image:: /media/image2.png

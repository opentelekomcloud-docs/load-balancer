=========
Whitelist
=========

Adding a Whitelist
==================

Function
^^^^^^^^

This API is used to add a whitelist to control access to a specific listener.
After a whitelist is added, only IP addresses in the whitelist can access the
listener.

URI
^^^

POST /v2.0/lbaas/whitelists

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                  |
   +===========+===========+========+==============================================================+
   | whitelist | Yes       | Object | Specifies the whitelist. For details, see :ref:`swc_t2`.     |
   +-----------+-----------+--------+--------------------------------------------------------------+

.. _swc_t2:
.. table:: **Table 2** **whitelist** parameter description

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | tenant_id        | No        | String  | Specifies the ID of the     |
   |                  |           |         | project where the whitelist |
   |                  |           |         | is used.                    |
   |                  |           |         |                             |
   |                  |           |         | The value must be the same  |
   |                  |           |         | as the value of             |
   |                  |           |         | **project_id** in the       |
   |                  |           |         | token.                      |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | listener_id      | Yes       | String  | Specifies the listener ID.  |
   |                  |           |         |                             |
   |                  |           |         | Only one whitelist can be   |
   |                  |           |         | created for a listener.     |
   +------------------+-----------+---------+-----------------------------+
   | enable_whitelist | No        | Boolean | Specifies whether to enable |
   |                  |           |         | access control.             |
   |                  |           |         |                             |
   |                  |           |         | **true**: Access control is |
   |                  |           |         | enabled.                    |
   |                  |           |         |                             |
   |                  |           |         | **false**: Access control   |
   |                  |           |         | is disabled.                |
   |                  |           |         |                             |
   |                  |           |         | The default value is        |
   |                  |           |         | **true**.                   |
   +------------------+-----------+---------+-----------------------------+
   | whitelist        | No        | String  | Specifies the IP addresses  |
   |                  |           |         | in the whitelist. Use       |
   |                  |           |         | commas (,) to separate      |
   |                  |           |         | multiple IP addresses.      |
   |                  |           |         |                             |
   |                  |           |         | You can specify an IP       |
   |                  |           |         | address, for example,       |
   |                  |           |         | 192.168.11.1.               |
   |                  |           |         |                             |
   |                  |           |         | You can also specify an IP  |
   |                  |           |         | address range, for example, |
   |                  |           |         | 192.168.0.1/24.             |
   |                  |           |         |                             |
   |                  |           |         | The default value is an     |
   |                  |           |         | empty string, that is,      |
   |                  |           |         | **""**.                     |
   +------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 3** Response parameters

   +-----------+--------+---------------------------------------------------------------+
   | Parameter | Type   | Description                                                   |
   +===========+========+===============================================================+
   | whitelist | Object | Specifies the whitelist. For details, see :ref:`swc_t4`.      |
   +-----------+--------+---------------------------------------------------------------+

.. _swc_t4:
.. table:: **Table 4** **whitelist** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the whitelist ID.           |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the whitelist is used.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | listener_id      | String  | Specifies the ID of the listener to   |
   |                  |         | which the whitelist is added.         |
   +------------------+---------+---------------------------------------+
   | enable_whitelist | Boolean | Specifies whether to enable access    |
   |                  |         | control.                              |
   |                  |         |                                       |
   |                  |         | **true**: Access control is enabled.  |
   |                  |         |                                       |
   |                  |         | **false**: Access control is          |
   |                  |         | disabled.                             |
   +------------------+---------+---------------------------------------+
   | whitelist        | String  | Specifies the IP addresses in the     |
   |                  |         | whitelist.                            |
   +------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Adding a whitelist

.. code::

      POST https://{Endpoint}/v2.0/lbaas/whitelists

      {
          "whitelist": {
              "listener_id": "eabfefa3fd1740a88a47ad98e132d238",
              "enable_whitelist": true,
              "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "whitelist": {
              "id": "eabfefa3fd1740a88a47ad98e132d238",
              "listener_id": "eabfefa3fd1740a88a47ad98e132d238",
              "tenant_id": "eabfefa3fd1740a88a47ad98e132d238",
              "enable_whitelist": true,
              "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Whitelists
===================

Function
^^^^^^^^

This API is used to query the whitelists. Filter query and pagination query are
supported. Unless otherwise specified, exact match is applied.

Constraints
^^^^^^^^^^^

Parameters **marker**, **limit**, and **page_reverse** are used for pagination
query. Parameters **marker** and **page_reverse** take effect only when they
are used together with parameter **limit**.

URI
^^^

GET /v2.0/lbaas/whitelists

Request
^^^^^^^

.. table:: **Table 1** Parameter description

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | marker           | No        | String  | Specifies the ID of the     |
   |                  |           |         | whitelist from which        |
   |                  |           |         | pagination query starts,    |
   |                  |           |         | that is, the ID of the last |
   |                  |           |         | whitelist on the previous   |
   |                  |           |         | page.                       |
   |                  |           |         |                             |
   |                  |           |         | This parameter must be used |
   |                  |           |         | together with **limit**.    |
   +------------------+-----------+---------+-----------------------------+
   | limit            | No        | Integer | Specifies the number of     |
   |                  |           |         | whitelists on each page. If |
   |                  |           |         | this parameter is not set,  |
   |                  |           |         | all whitelists are queried  |
   |                  |           |         | by default.                 |
   +------------------+-----------+---------+-----------------------------+
   | page_reverse     | No        | Boolean | Specifies the page          |
   |                  |           |         | direction. The value can be |
   |                  |           |         | **true** or **false**, and  |
   |                  |           |         | the default value is        |
   |                  |           |         | **false**. The last page in |
   |                  |           |         | the list requested with     |
   |                  |           |         | **page_reverse** set to     |
   |                  |           |         | **false** will not contain  |
   |                  |           |         | the "next" link, and the    |
   |                  |           |         | last page in the list       |
   |                  |           |         | requested with              |
   |                  |           |         | **page_reverse** set to     |
   |                  |           |         | **true** will not contain   |
   |                  |           |         | the "previous" link.        |
   |                  |           |         |                             |
   |                  |           |         | This parameter must be used |
   |                  |           |         | together with **limit**.    |
   +------------------+-----------+---------+-----------------------------+
   | id               | No        | String  | Specifies the whitelist ID. |
   +------------------+-----------+---------+-----------------------------+
   | tenant_id        | No        | String  | Specifies the ID of the     |
   |                  |           |         | project where the whitelist |
   |                  |           |         | is used.                    |
   |                  |           |         |                             |
   |                  |           |         | The value contains a        |
   |                  |           |         | maximum of 255 characters.  |
   +------------------+-----------+---------+-----------------------------+
   | listener_id      | No        | String  | Specifies the ID of the     |
   |                  |           |         | listener to which the       |
   |                  |           |         | whitelist is added.         |
   +------------------+-----------+---------+-----------------------------+
   | enable_whitelist | No        | Boolean | Specifies whether to enable |
   |                  |           |         | access control.             |
   |                  |           |         |                             |
   |                  |           |         | **true**: Access control is |
   |                  |           |         | enabled.                    |
   |                  |           |         |                             |
   |                  |           |         | **false**: Access control   |
   |                  |           |         | is disabled.                |
   +------------------+-----------+---------+-----------------------------+
   | whitelist        | No        | String  | Specifies the IP addresses  |
   |                  |           |         | in the whitelist.           |
   +------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +------------------+-------+---------------------------------------+
   | Parameter        | Type  | Description                           |
   +==================+=======+=======================================+
   | whitelists       | Array | Lists the whitelists. For details,    |
   |                  |       | see :ref:`swl_t3`.                    |
   +------------------+-------+---------------------------------------+
   | whitelists_links | Array | Provides links to the previous or     |
   |                  |       | next page during pagination query,    |
   |                  |       | respectively.                         |
   |                  |       |                                       |
   |                  |       | This parameter exists only in the     |
   |                  |       | response body of pagination query.    |
   |                  |       |                                       |
   |                  |       | For details, see :ref:`swl_t4`.       |
   +------------------+-------+---------------------------------------+

.. _swl_t3:
.. table:: **Table 3** **whitelist** parameter description

   +------------------+--------+---------------------------------------+
   | Parameter        | Type   | Description                           |
   +==================+========+=======================================+
   | id               | String | Specifies the whitelist ID.           |
   +------------------+--------+---------------------------------------+
   | tenant_id        | String | Specifies the ID of the project where |
   |                  |        | the whitelist is used.                |
   |                  |        |                                       |
   |                  |        | The value contains a maximum of 255   |
   |                  |        | characters.                           |
   +------------------+--------+---------------------------------------+
   | listener_id      | String | Specifies the ID of the listener to   |
   |                  |        | which the whitelist is added.         |
   +------------------+--------+---------------------------------------+
   | enable_whitelist | Bool   | Specifies whether to enable access    |
   |                  |        | control.                              |
   |                  |        |                                       |
   |                  |        | **true**: Access control is enabled.  |
   |                  |        |                                       |
   |                  |        | **false**: Access control is          |
   |                  |        | disabled.                             |
   +------------------+--------+---------------------------------------+
   | whitelist        | String | Specifies the IP addresses in the     |
   |                  |        | whitelist.                            |
   +------------------+--------+---------------------------------------+

.. _swl_t4:
.. table:: **Table 4** **whitelists_links** parameter description

   +-----------+--------+---------------------------------------+
   | Parameter | Type   | Description                           |
   +===========+========+=======================================+
   | href      | String | Provides links to the previous or     |
   |           |        | next page during pagination query,    |
   |           |        | respectively.                         |
   +-----------+--------+---------------------------------------+
   | rel       | String | Specifies the prompt of the previous  |
   |           |        | or next page.                         |
   |           |        |                                       |
   |           |        | The value can be **next** or          |
   |           |        | **previous**. The value **next**      |
   |           |        | indicates the href containing the URL |
   |           |        | of the next page, and **previous**    |
   |           |        | indicates the href containing the URL |
   |           |        | of the previous page.                 |
   +-----------+--------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request 1: Querying all whitelists

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/whitelists

-  Example request 2: Querying the whitelists added to listener
   eabfefa3fd1740a88a47ad98e132d230

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/whitelists?listener_id=eabfefa3fd1740a88a47ad98e132d230

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   .. code::

      {
          "whitelists": [
              {
                  "id": "eabfefa3fd1740a88a47ad98e132d238",
                  "listener_id": "eabfefa3fd1740a88a47ad98e132d238",
                  "tenant_id": "eabfefa3fd1740a88a47ad98e132d238",
                  "enable_whitelist": true,
                  "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
              },
              {
                  "id": "eabfefa3fd1740a88a47ad98e132d326",
                  "listener_id": "eabfefa3fd1740a88a47ad98e132d327",
                  "tenant_id": "eabfefa3fd1740a88a47ad98e132d436",
                  "enable_whitelist": true,
                  "whiltelist": "192.168.12.1,192.168.1.1/24,192.168.203.18/8,100.164.5.1/24"
              }
          ]
      }

-  Example response 2

   .. code::

      {
          "whitelists": [
              {
                  "id": "eabfefa3fd1740a88a47ad98e132d238",
                  "listener_id": "eabfefa3fd1740a88a47ad98e132d230",
                  "tenant_id": "eabfefa3fd1740a88a47ad98e132d239",
                  "enable_whitelist": true,
                  "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
              },
              {
                  "id": "eabfefa3fd1740a88a47ad98e132d326",
                  "listener_id": "eabfefa3fd1740a88a47ad98e132d327",
                  "tenant_id": "eabfefa3fd1740a88a47ad98e132d439",
                  "enable_whitelist": true,
                  "whiltelist": "192.168.12.1,192.168.1.1/24,192.168.203.18/8,100.164.5.1/24"
              }
          ]
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Querying Details of a Whitelist
===============================

Function
^^^^^^^^

This API is used to query details about a whitelist using its ID.

URI
^^^

GET /v2.0/lbaas/whitelists/{whitelist_id}

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===========================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========================
   whitelist_id Yes       String Specifies the whitelist ID.
   ============ ========= ====== ===========================

Request
^^^^^^^

None

Response
^^^^^^^^

.. table:: **Table 2** Response parameters

   +-----------+--------+---------------------------------------------------------------+
   | Parameter | Type   | Description                                                   |
   +===========+========+===============================================================+
   | whitelist | Object | Specifies the whitelist. For details, see :ref:`sws_t3`.      |
   +-----------+--------+---------------------------------------------------------------+

.. _sws_t3:
.. table:: **Table 3** **whitelist** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the whitelist ID.           |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the forwarding rule is used.          |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | listener_id      | String  | Specifies the ID of the listener to   |
   |                  |         | which the whitelist is added.         |
   +------------------+---------+---------------------------------------+
   | enable_whitelist | Boolean | Specifies whether to enable access    |
   |                  |         | control.                              |
   |                  |         |                                       |
   |                  |         | **true**: Access control is enabled.  |
   |                  |         |                                       |
   |                  |         | **false**: Access control is          |
   |                  |         | disabled.                             |
   +------------------+---------+---------------------------------------+
   | whitelist        | String  | Specifies the IP addresses in the     |
   |                  |         | whitelist.                            |
   +------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Querying details of a whitelist

   .. code::

      GET https://{Endpoint}/v2.0/lbaas/whitelists/09e64049-2ab0-4763-a8c5-f4207875dc3e

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "whitelist": {
              "id": "eabfefa3fd1740a88a47ad98e132d238",
              "listener_id": "eabfefa3fd1740a88a47ad98e132d238",
              "tenant_id": "eabfefa3fd1740a88a47ad98e132d238",
              "enable_whitelist": true,
              "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Updating a Whitelist
====================

Function
^^^^^^^^

This API is used to update a whitelist. You can enable or disable the whitelist
function or change IP addresses in the whitelist. If you change IP addresses in
the whitelist, it will be deleted, and a new one is generated.

URI
^^^

PUT /v2.0/lbaas/whitelists/{whitelist_id}

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===========================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========================
   whitelist_id Yes       String Specifies the whitelist ID.
   ============ ========= ====== ===========================

Request
^^^^^^^

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+--------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                  |
   +===========+===========+========+==============================================================+
   | whitelist | Yes       | Object | Specifies the whitelist. For details, see :ref:`swu_t3`.     |
   +-----------+-----------+--------+--------------------------------------------------------------+

.. _swu_t3:
.. table:: **Table 3** **whitelist** parameter description

   +------------------+-----------+---------+-----------------------------+
   | Parameter        | Mandatory | Type    | Description                 |
   +==================+===========+=========+=============================+
   | enable_whitelist | No        | Boolean | Specifies whether to enable |
   |                  |           |         | access control.             |
   |                  |           |         |                             |
   |                  |           |         | **true**: Access control is |
   |                  |           |         | enabled.                    |
   |                  |           |         |                             |
   |                  |           |         | **false**: Access control   |
   |                  |           |         | is disabled.                |
   |                  |           |         |                             |
   |                  |           |         | The default value is        |
   |                  |           |         | **true**.                   |
   +------------------+-----------+---------+-----------------------------+
   | whitelist        | No        | String  | Specifies the IP addresses  |
   |                  |           |         | in the whitelist. Use       |
   |                  |           |         | commas (,) to separate      |
   |                  |           |         | multiple IP addresses.      |
   |                  |           |         |                             |
   |                  |           |         | You can specify an IP       |
   |                  |           |         | address, for example,       |
   |                  |           |         | 192.168.11.1.               |
   |                  |           |         |                             |
   |                  |           |         | You can also specify an IP  |
   |                  |           |         | address range, for example, |
   |                  |           |         | 192.168.0.1/24.             |
   |                  |           |         |                             |
   |                  |           |         | The default value is an     |
   |                  |           |         | empty string, that is,      |
   |                  |           |         | **""**.                     |
   +------------------+-----------+---------+-----------------------------+

Response
^^^^^^^^

.. table:: **Table 4** Parameter description

   +-----------+--------+--------------------------------------------------------------+
   | Parameter | Type   | Description                                                  |
   +===========+========+==============================================================+
   | whitelist | Object | Specifies the whitelist. For details, see :ref:`swu_t5`.     |
   +-----------+--------+--------------------------------------------------------------+

.. _swu_t5:
.. table:: **Table 5** **whitelist** parameter description

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | id               | String  | Specifies the whitelist ID.           |
   +------------------+---------+---------------------------------------+
   | tenant_id        | String  | Specifies the ID of the project where |
   |                  |         | the whitelist is used.                |
   |                  |         |                                       |
   |                  |         | The value contains a maximum of 255   |
   |                  |         | characters.                           |
   +------------------+---------+---------------------------------------+
   | listener_id      | String  | Specifies the ID of the listener to   |
   |                  |         | which the whitelist is added.         |
   +------------------+---------+---------------------------------------+
   | enable_whitelist | Boolean | Specifies whether to enable access    |
   |                  |         | control.                              |
   |                  |         |                                       |
   |                  |         | **true**: Access control is enabled.  |
   |                  |         |                                       |
   |                  |         | **false**: Access control is          |
   |                  |         | disabled.                             |
   +------------------+---------+---------------------------------------+
   | whitelist        | String  | Specifies the IP addresses in the     |
   |                  |         | whitelist.                            |
   +------------------+---------+---------------------------------------+

Example Request
^^^^^^^^^^^^^^^

-  Example request: Updating a whitelist

   .. code::

      PUT https://{Endpoint}/v2.0/lbaas/whitelists/dcaf46f1-037c-4f63-a31f-e0c4c18032c7

      {
          "whitelist": {
              "enable_whitelist": true,
              "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
          }
      }

Example Response
^^^^^^^^^^^^^^^^

-  Example response

   .. code::

      {
          "whitelist": {
              "id": "eabfefa3fd1740a88a47ad98e132d238",
              "listener_id": "eabfefa3fd1740a88a47ad98e132d238",
              "tenant_id": "eabfefa3fd1740a88a47ad98e132d238",
              "enable_whitelist": true,
              "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
          }
      }

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

Deleting a Whitelist
====================

Function
^^^^^^^^

This API is used to delete a specific whitelist.

URI
^^^

DELETE /v2.0/lbaas/whitelists/{whitelist_id}

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===========================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========================
   whitelist_id Yes       String Specifies the whitelist ID.
   ============ ========= ====== ===========================

Request
^^^^^^^

None

Response
^^^^^^^^

None

Example Request
^^^^^^^^^^^^^^^

-  Example request: Deleting a whitelist

   .. code::

      DELETE https://{Endpoint}/v2.0/lbaas/whitelists/35cb8516-1173-4035-8dae-0dae3453f37f

Example Response
^^^^^^^^^^^^^^^^

-  Example response 1

   None

Status Code
^^^^^^^^^^^

See :ref:`shared_lb_status_code`.

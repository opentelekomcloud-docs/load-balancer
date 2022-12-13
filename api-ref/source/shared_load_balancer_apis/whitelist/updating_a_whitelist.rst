:original_name: elb_zq_bm_0004.html

.. _elb_zq_bm_0004:

Updating a Whitelist
====================

Function
--------

This API is used to update a whitelist. You can enable or disable the whitelist function or change IP addresses in the whitelist. If you change IP addresses in the whitelist, it will be deleted, and a new one is generated.

URI
---

PUT /v2.0/lbaas/whitelists/{whitelist_id}

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===========================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========================
   whitelist_id Yes       String Specifies the whitelist ID.
   ============ ========= ====== ===========================

Request
-------

.. table:: **Table 2** Parameter description

   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                     |
   +===========+===========+========+=================================================================================================================+
   | whitelist | Yes       | Object | Specifies the whitelist. For details, see :ref:`Table 3 <elb_zq_bm_0004__en-us_topic_0143878054_table8047771>`. |
   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bm_0004__en-us_topic_0143878054_table8047771:

.. table:: **Table 3** **whitelist** parameter description

   +------------------+-----------------+-----------------+------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                    |
   +==================+=================+=================+================================================================================================+
   | enable_whitelist | No              | Boolean         | Specifies whether to enable access control.                                                    |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | **true**: Access control is enabled.                                                           |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | **false**: Access control is disabled.                                                         |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | The default value is **true**.                                                                 |
   +------------------+-----------------+-----------------+------------------------------------------------------------------------------------------------+
   | whitelist        | No              | String          | Specifies the IP addresses in the whitelist. Use commas (,) to separate multiple IP addresses. |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | You can specify an IP address, for example, 192.168.11.1.                                      |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | You can also specify an IP address range, for example, 192.168.0.1/24.                         |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | The default value is an empty string, that is, **""**.                                         |
   +------------------+-----------------+-----------------+------------------------------------------------------------------------------------------------+

Response
--------

.. table:: **Table 4** Parameter description

   +-----------+--------+-----------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                     |
   +===========+========+=================================================================================================================+
   | whitelist | Object | Specifies the whitelist. For details, see :ref:`Table 5 <elb_zq_bm_0004__en-us_topic_0143878054_table5548368>`. |
   +-----------+--------+-----------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bm_0004__en-us_topic_0143878054_table5548368:

.. table:: **Table 5** **whitelist** parameter description

   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                       |
   +=======================+=======================+===================================================================+
   | id                    | String                | Specifies the whitelist ID.                                       |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the whitelist is used.      |
   |                       |                       |                                                                   |
   |                       |                       | The value contains a maximum of 255 characters.                   |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | listener_id           | String                | Specifies the ID of the listener to which the whitelist is added. |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | enable_whitelist      | Boolean               | Specifies whether to enable access control.                       |
   |                       |                       |                                                                   |
   |                       |                       | **true**: Access control is enabled.                              |
   |                       |                       |                                                                   |
   |                       |                       | **false**: Access control is disabled.                            |
   +-----------------------+-----------------------+-------------------------------------------------------------------+
   | whitelist             | String                | Specifies the IP addresses in the whitelist.                      |
   +-----------------------+-----------------------+-------------------------------------------------------------------+

Example Request
---------------

-  Example request: Updating a whitelist

   .. code-block:: text

      PUT https://{Endpoint}/v2.0/lbaas/whitelists/dcaf46f1-037c-4f63-a31f-e0c4c18032c7

      {
          "whitelist": {
              "enable_whitelist": true,
              "whitelist": "192.168.11.1,192.168.0.1/24,192.168.201.18/8,100.164.0.1/24"
          }
      }

Example Response
----------------

-  Example response

   .. code-block::

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
-----------

For details, see :ref:`HTTP Status Codes of Shared Load Balancers <elb_gc_0002>`.

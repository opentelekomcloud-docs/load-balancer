:original_name: elb_zq_bm_0003.html

.. _elb_zq_bm_0003:

Querying Details of a Whitelist
===============================

Function
--------

This API is used to query details about a whitelist using its ID.

URI
---

GET /v2.0/lbaas/whitelists/{whitelist_id}

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===========================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===========================
   whitelist_id Yes       String Specifies the whitelist ID.
   ============ ========= ====== ===========================

Request
-------

None

Response
--------

.. table:: **Table 2** Response parameters

   +-----------+--------+------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                      |
   +===========+========+==================================================================================================================+
   | whitelist | Object | Specifies the whitelist. For details, see :ref:`Table 3 <elb_zq_bm_0003__en-us_topic_0143878051_table21950591>`. |
   +-----------+--------+------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bm_0003__en-us_topic_0143878051_table21950591:

.. table:: **Table 3** **whitelist** parameter description

   +-----------------------+-----------------------+--------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                        |
   +=======================+=======================+====================================================================+
   | id                    | String                | Specifies the whitelist ID.                                        |
   +-----------------------+-----------------------+--------------------------------------------------------------------+
   | tenant_id             | String                | Specifies the ID of the project where the forwarding rule is used. |
   |                       |                       |                                                                    |
   |                       |                       | The value contains a maximum of 255 characters.                    |
   +-----------------------+-----------------------+--------------------------------------------------------------------+
   | listener_id           | String                | Specifies the ID of the listener to which the whitelist is added.  |
   +-----------------------+-----------------------+--------------------------------------------------------------------+
   | enable_whitelist      | Boolean               | Specifies whether to enable access control.                        |
   |                       |                       |                                                                    |
   |                       |                       | **true**: Access control is enabled.                               |
   |                       |                       |                                                                    |
   |                       |                       | **false**: Access control is disabled.                             |
   +-----------------------+-----------------------+--------------------------------------------------------------------+
   | whitelist             | String                | Specifies the IP addresses in the whitelist.                       |
   +-----------------------+-----------------------+--------------------------------------------------------------------+

Example Request
---------------

-  Example request: Querying details of a whitelist

   .. code-block:: text

      GET https://{Endpoint}/v2.0/lbaas/whitelists/09e64049-2ab0-4763-a8c5-f4207875dc3e

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

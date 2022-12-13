:original_name: elb_zq_bm_0001.html

.. _elb_zq_bm_0001:

Adding a Whitelist
==================

Function
--------

This API is used to add a whitelist to control access to a specific listener. After a whitelist is added, only IP addresses in the whitelist can access the listener.

URI
---

POST /v2.0/lbaas/whitelists

Request
-------

.. table:: **Table 1** Parameter description

   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------+
   | Parameter | Mandatory | Type   | Description                                                                                                     |
   +===========+===========+========+=================================================================================================================+
   | whitelist | Yes       | Object | Specifies the whitelist. For details, see :ref:`Table 2 <elb_zq_bm_0001__en-us_topic_0143878053_table7163025>`. |
   +-----------+-----------+--------+-----------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bm_0001__en-us_topic_0143878053_table7163025:

.. table:: **Table 2** **whitelist** parameter description

   +------------------+-----------------+-----------------+------------------------------------------------------------------------------------------------+
   | Parameter        | Mandatory       | Type            | Description                                                                                    |
   +==================+=================+=================+================================================================================================+
   | tenant_id        | No              | String          | Specifies the ID of the project where the whitelist is used.                                   |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | The value must be the same as the value of **project_id** in the token.                        |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | The value contains a maximum of 255 characters.                                                |
   +------------------+-----------------+-----------------+------------------------------------------------------------------------------------------------+
   | listener_id      | Yes             | String          | Specifies the listener ID.                                                                     |
   |                  |                 |                 |                                                                                                |
   |                  |                 |                 | Only one whitelist can be created for a listener.                                              |
   +------------------+-----------------+-----------------+------------------------------------------------------------------------------------------------+
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

.. table:: **Table 3** Response parameters

   +-----------+--------+------------------------------------------------------------------------------------------------------------------+
   | Parameter | Type   | Description                                                                                                      |
   +===========+========+==================================================================================================================+
   | whitelist | Object | Specifies the whitelist. For details, see :ref:`Table 4 <elb_zq_bm_0001__en-us_topic_0143878053_table24244005>`. |
   +-----------+--------+------------------------------------------------------------------------------------------------------------------+

.. _elb_zq_bm_0001__en-us_topic_0143878053_table24244005:

.. table:: **Table 4** **whitelist** parameter description

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

-  Example request: Adding a whitelist

   .. code-block:: text

      POST https://{Endpoint}/v2.0/lbaas/whitelists

      {
          "whitelist": {
              "listener_id": "eabfefa3fd1740a88a47ad98e132d238",
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

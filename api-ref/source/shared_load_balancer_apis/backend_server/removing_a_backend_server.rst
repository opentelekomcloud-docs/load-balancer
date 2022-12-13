:original_name: elb_zq_hd_0005.html

.. _elb_zq_hd_0005:

Removing a Backend Server
=========================

Function
--------

This API is used to remove a backend server by its ID.

Constraints
-----------

After you remove a backend server, new connections to this server will not be established. However, long connections that have been established will be maintained.

URI
---

DELETE /v2.0/lbaas/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Parameter description

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                                |
   +=================+=================+=================+============================================================================================================================================================================+
   | pool_id         | Yes             | String          | Specifies the ID of the backend server group.                                                                                                                              |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_id       | Yes             | String          | Specifies the backend server ID.                                                                                                                                           |
   |                 |                 |                 |                                                                                                                                                                            |
   |                 |                 |                 | .. note::                                                                                                                                                                  |
   |                 |                 |                 |                                                                                                                                                                            |
   |                 |                 |                 |    -  The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer. |
   |                 |                 |                 |    -  You can obtain this value by calling the API described in :ref:`Querying Backend Servers <elb_zq_hd_0002>`.                                                          |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Request
-------

None

Response
--------

None

Example Request
---------------

-  Example request: Removing a backend server

   .. code-block:: text

      DELETE https://{Endpoint}/v2.0/lbaas/pools/5a9a3e9e-d1aa-448e-af37-a70171f2a332/members/cf024846-7516-4e3a-b0fb-6590322c836f

Example Response
----------------

-  Example response

   None

Status Code
-----------

For details, see :ref:`Status Codes <elb_gc_1102>`.

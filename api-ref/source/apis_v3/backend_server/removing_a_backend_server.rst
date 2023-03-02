:original_name: DeleteMember.html

.. _DeleteMember:

Removing a Backend Server
=========================

Function
--------

This API is used to remove a backend server.

Constraints
-----------

After you remove a backend server, new connections to this server will not be established. However, persistent connections that have been established will be maintained.

URI
---

DELETE /v3/{project_id}/elb/pools/{pool_id}/members/{member_id}

.. table:: **Table 1** Path Parameters

   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                                                                          |
   +=================+=================+=================+======================================================================================================================================================================+
   | project_id      | Yes             | String          | Specifies the project ID.                                                                                                                                            |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | pool_id         | Yes             | String          | Specifies the ID of the backend server group.                                                                                                                        |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | member_id       | Yes             | String          | Specifies the backend server ID.                                                                                                                                     |
   |                 |                 |                 |                                                                                                                                                                      |
   |                 |                 |                 | Note:                                                                                                                                                                |
   |                 |                 |                 |                                                                                                                                                                      |
   |                 |                 |                 | The value of this parameter is not the ID of the server but an ID automatically generated for the backend server that has already associated with the load balancer. |
   +-----------------+-----------------+-----------------+----------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

Response Parameters
-------------------

None

Example Requests
----------------

.. code-block:: text

   DELETE https://{ELB_Endpoint}/v3/99a3fff0d03c428eac3678da6a7d0f24/elb/pools/36ce7086-a496-4666-9064-5ba0e6840c75/members/1923923e-fe8a-484f-bdbc-e11559b1f48f

Example Responses
-----------------

None

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
204         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.

.. -*- rst -*-

Querying Quotas
===============

Function
^^^^^^^^

This API is used to query resource quotas of a specific user.

URI
^^^

GET /v3/{project_id}/elb/quotas

.. table:: **Table 1** Path parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request Parameters
^^^^^^^^^^^^^^^^^^

.. table:: **Table 2** Request header parameters

   ============ ========= ====== ================================================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ================================================
   X-Auth-Token Yes       String Specifies the token used for IAM authentication.
   ============ ========= ====== ================================================

Response Parameters
^^^^^^^^^^^^^^^^^^^

**Status code: 200**

.. table:: **Table 3** Response body parameters

   ========== ================ ===============================================================
   Parameter  Type             Description
   ========== ================ ===============================================================
   request_id String           Specifies the request ID. The value is automatically generated.
   quota      :ref:`dq` object Specifies the quota details.
   ========== ================ ===============================================================

.. _dq:
.. table:: **Table 4** Quota

   +------------------+---------+---------------------------------------+
   | Parameter        | Type    | Description                           |
   +==================+=========+=======================================+
   | certificate      | Integer | Specifies the certificate quota.      |
   |                  |         | **-1** indicates that the quota is    |
   |                  |         | not limited.                          |
   +------------------+---------+---------------------------------------+
   | healthmonitor    | Integer | Specifies the health check quota.     |
   |                  |         | **-1** indicates that the quota is    |
   |                  |         | not limited.                          |
   +------------------+---------+---------------------------------------+
   | l7policy         | Integer | Specifies the forwarding policy       |
   |                  |         | quota. **-1** indicates that the      |
   |                  |         | quota is not limited.                 |
   +------------------+---------+---------------------------------------+
   | listener         | Integer | Specifies the listener quota. **-1**  |
   |                  |         | indicates that the quota is not       |
   |                  |         | limited.                              |
   +------------------+---------+---------------------------------------+
   | loadbalancer     | Integer | Specifies the load balancer quota.    |
   |                  |         | **-1** indicates that the quota is    |
   |                  |         | not limited.                          |
   +------------------+---------+---------------------------------------+
   | member           | Integer | Specifies the backend server quota.   |
   |                  |         | **-1** indicates that the quota is    |
   |                  |         | not limited.                          |
   +------------------+---------+---------------------------------------+
   | members_per_pool | Integer | Specifies the quota of backend        |
   |                  |         | servers in a backend server group.    |
   |                  |         | **-1** indicates that the quota is    |
   |                  |         | not limited.                          |
   +------------------+---------+---------------------------------------+
   | pool             | Integer | Specifies the backend server group    |
   |                  |         | quota. **-1** indicates that the      |
   |                  |         | quota is not limited.                 |
   +------------------+---------+---------------------------------------+
   | ipgroup          | Integer | Specifies the IP address group quota. |
   |                  |         | **-1** indicates that the quota is    |
   |                  |         | not limited.                          |
   |                  |         |                                       |
   |                  |         | This parameter is unsupported. Please |
   |                  |         | do not use it.                        |
   +------------------+---------+---------------------------------------+
   | project_id       | String  | Specifies the project ID.             |
   +------------------+---------+---------------------------------------+

Example Requests
^^^^^^^^^^^^^^^^

.. code::

   GET https://{elb_endpoint}/v3/{project_id}/elb/quotas

Example Responses
^^^^^^^^^^^^^^^^^

**Status code: 200**

Successful request.

.. code::

   {
     "quota" : {
       "member" : 500,
       "members_per_pool" : 500,
       "certificate" : 120,
       "l7policy" : 500,
       "listener" : 100,
       "loadbalancer" : 50,
       "healthmonitor" : -1,
       "ipgroup" : 50,
       "pool" : 500,
       "project_id" : "99a3fff0d03c428eac3678da6a7d0f24"
     },
     "request_id" : "8d7eba6f-ec79-42d2-8d8c-16149645549d"
   }

Status Codes
^^^^^^^^^^^^

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
^^^^^^^^^^^

See :ref:`dsc`.

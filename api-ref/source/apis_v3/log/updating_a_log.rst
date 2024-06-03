:original_name: UpdateLogtank.html

.. _UpdateLogtank:

Updating a Log
==============

Function
--------

This API is used to update a log.

URI
---

PUT /v3/{project_id}/elb/logtanks/{logtank_id}

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   logtank_id Yes       String Specifies the log ID.
   ========== ========= ====== =========================

Request Parameters
------------------

.. table:: **Table 2** Request header parameters

   +--------------+-----------+--------+--------------------------------------------------+
   | Parameter    | Mandatory | Type   | Description                                      |
   +==============+===========+========+==================================================+
   | X-Auth-Token | Yes       | String | Specifies the token used for IAM authentication. |
   +--------------+-----------+--------+--------------------------------------------------+

.. table:: **Table 3** Request body parameters

   +-----------+-----------+--------------------------------------------------------------------------------+-----------------------------------------------------+
   | Parameter | Mandatory | Type                                                                           | Description                                         |
   +===========+===========+================================================================================+=====================================================+
   | logtank   | Yes       | :ref:`UpdateLogtankOption <updatelogtank__request_updatelogtankoption>` object | Specifies the request parameter for updating a log. |
   +-----------+-----------+--------------------------------------------------------------------------------+-----------------------------------------------------+

.. _updatelogtank__request_updatelogtankoption:

.. table:: **Table 4** UpdateLogtankOption

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                  |
   +=================+=================+=================+==============================================================================================================+
   | log_group_id    | No              | String          | Specifies the log group ID. This parameter is available for all services other than ELB.                     |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Minimum: **1**                                                                                               |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Maximum: **36**                                                                                              |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+
   | log_topic_id    | No              | String          | Specifies the ID of the log subscription topic. This parameter is available for all services other than ELB. |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Minimum: **1**                                                                                               |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Maximum: **36**                                                                                              |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 5** Response body parameters

   +------------+---------------------------------------------------------+----------------------------------------------------------------+
   | Parameter  | Type                                                    | Description                                                    |
   +============+=========================================================+================================================================+
   | request_id | String                                                  | Specifies the response body to the request for updating a log. |
   +------------+---------------------------------------------------------+----------------------------------------------------------------+
   | logtank    | :ref:`Logtank <updatelogtank__response_logtank>` object | Specifies the log details.                                     |
   +------------+---------------------------------------------------------+----------------------------------------------------------------+

.. _updatelogtank__response_logtank:

.. table:: **Table 6** Logtank

   =============== ====== ====================================
   Parameter       Type   Description
   =============== ====== ====================================
   id              String Specifies the log ID.
   project_id      String Specifies the ID of a load balancer.
   loadbalancer_id String Specifies the ID of a load balancer.
   log_group_id    String Specifies the log group ID.
   log_topic_id    String Specifies the log topic ID.
   =============== ====== ====================================

Example Requests
----------------

Updating a log

.. code-block:: text

   PUT https://{ELB_Endpoint}/v3/060576798a80d5762fafc01a9b5eedc7/elb/logtanks/603e507f-3e18-498b-9460-01a3b6c28fc5

   {
     "logtank" : {
       "log_topic_id" : "5b9b8370-a1fc-4c59-a509-483a673c8a94",
       "log_group_id" : "7733882e-f7fa-4fb0-a460-0605c48a2280"
     }
   }

Example Responses
-----------------

**Status code: 200**

OK

.. code-block::

   {
     "logtank" : {
       "project_id" : "060576798a80d5762fafc01a9b5eedc7",
       "log_topic_id" : "5b9b8370-a1fc-4c59-a509-483a673c8a94",
       "id" : "603e507f-3e18-498b-9460-01a3b6c28fc5",
       "log_group_id" : "7733882e-f7fa-4fb0-a460-0605c48a2280",
       "loadbalancer_id" : "47ecc304-3f1a-4cc6-9c1c-72add483b9ce"
     },
     "request_id" : "59662f86620f8fc09c908eed060a2f0e"
   }

Status Codes
------------

=========== ===========
Status Code Description
=========== ===========
200         OK
=========== ===========

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.

:original_name: CreateLogtank.html

.. _CreateLogtank:

Creating a Log
==============

Function
--------

This API is used to create a log.

URI
---

POST /v3/{project_id}/elb/logtanks

.. table:: **Table 1** Path Parameters

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
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
   | logtank   | Yes       | :ref:`CreateLogtankOption <createlogtank__request_createlogtankoption>` object | Specifies the request parameter for creating a log. |
   +-----------+-----------+--------------------------------------------------------------------------------+-----------------------------------------------------+

.. _createlogtank__request_createlogtankoption:

.. table:: **Table 4** CreateLogtankOption

   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+
   | Parameter       | Mandatory       | Type            | Description                                                                                                  |
   +=================+=================+=================+==============================================================================================================+
   | loadbalancer_id | Yes             | String          | Specifies the load balancer ID.                                                                              |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Minimum: **1**                                                                                               |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Maximum: **36**                                                                                              |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+
   | log_group_id    | Yes             | String          | Specifies the log group ID. This parameter is available for all services other than ELB.                     |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Minimum: **1**                                                                                               |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Maximum: **36**                                                                                              |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+
   | log_topic_id    | Yes             | String          | Specifies the ID of the log subscription topic. This parameter is available for all services other than ELB. |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Minimum: **1**                                                                                               |
   |                 |                 |                 |                                                                                                              |
   |                 |                 |                 | Maximum: **36**                                                                                              |
   +-----------------+-----------------+-----------------+--------------------------------------------------------------------------------------------------------------+

Response Parameters
-------------------

**Status code: 201**

.. table:: **Table 5** Response body parameters

   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | Parameter  | Type                                                    | Description                                                     |
   +============+=========================================================+=================================================================+
   | logtank    | :ref:`Logtank <createlogtank__response_logtank>` object | Provides supplementary information.                             |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+
   | request_id | String                                                  | Specifies the request ID. The value is automatically generated. |
   +------------+---------------------------------------------------------+-----------------------------------------------------------------+

.. _createlogtank__response_logtank:

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

Creating a log for a load balancer

.. code-block:: text

   POST https://{ELB_Endpoint}/v3/060576798a80d5762fafc01a9b5eedc7/elb/logtanks

   {
     "logtank" : {
       "log_topic_id" : "5b9b8370-a1fc-4c59-a509-483a673c8a94",
       "log_group_id" : "7733882e-f7fa-4fb0-a460-0605c48a2280",
       "loadbalancer_id" : "47ecc304-3f1a-4cc6-9c1c-72add483b9ce"
     }
   }

Example Responses
-----------------

**Status code: 201**

Created

.. code-block::

   {
     "request_id" : "c5aea69b657295bef71cd05da2959206",
     "logtank" : {
       "project_id" : "060576798a80d5762fafc01a9b5eedc7",
       "log_topic_id" : "5b9b8370-a1fc-4c59-a509-483a673c8a94",
       "id" : "603e507f-3e18-498b-9460-01a3b6c28fc5",
       "log_group_id" : "7733882e-f7fa-4fb0-a460-0605c48a2280",
       "loadbalancer_id" : "47ecc304-3f1a-4cc6-9c1c-72add483b9ce"
     }
   }

Status Codes
------------

=========== ===========
Status Code Description
=========== ===========
201         Created
=========== ===========

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.

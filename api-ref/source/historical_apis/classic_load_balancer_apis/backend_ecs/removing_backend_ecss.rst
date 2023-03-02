:original_name: elb_jd_hd_0002.html

.. _elb_jd_hd_0002:

Removing Backend ECSs
=====================

Function
--------

This API is used to remove backend ECSs from a listener. Multiple backend ECSs can be removed concurrently.

URI
---

POST /v1.0/{project_id}/elbaas/listeners/{listener_id}/members/action

.. table:: **Table 1** Parameter description

   ============ ========= ====== ===============================
   Parameter    Mandatory Type   Description
   ============ ========= ====== ===============================
   project_id   Yes       String Specifies the project ID.
   listener_id  Yes       String Specifies the listener ID.
   removeMember Yes       Array  Lists the removed backend ECSs.
   ============ ========= ====== ===============================

.. table:: **Table 2** **removeMember** parameter description

   ========= ========= ====== =============================
   Parameter Mandatory Type   Description
   ========= ========= ====== =============================
   id        Yes       String Specifies the backend ECS ID.
   ========= ========= ====== =============================

Request
-------

-  Request parameters

   None

-  Example request

   .. code-block::

      {
          "removeMember": [
              {
                  "id": "34695d664b182fa69b98228032b0e239"
              }
          ]
      }

Response
--------

-  Response parameters

   .. table:: **Table 3** Parameter description

      +-----------+--------+---------------------------------------------------------------------------------------------------+
      | Parameter | Type   | Description                                                                                       |
      +===========+========+===================================================================================================+
      | uri       | String | Specifies the URI returned by Combined API after the job for removing a backend ECS is delivered. |
      +-----------+--------+---------------------------------------------------------------------------------------------------+
      | job_id    | String | Specifies the unique ID assigned to the job for removing a backend ECS in Combined API.           |
      +-----------+--------+---------------------------------------------------------------------------------------------------+

-  Example response

   .. code-block::

      {
          "uri": "/v1/55300f3c8f764c06b1a32e2302edc305/jobs/4010b39b4fd3d5ff014fd3f160fd006c",
          "job_id": "4010b39b4fd3d5ff014fd3f160fd006c"
      }

Status Code
-----------

-  Normal

   200

-  Error

   +-------------+--------------------+----------------------------------------------------------+
   | Status Code | Message            | Description                                              |
   +=============+====================+==========================================================+
   | 400         | badRequest         | Request error.                                           |
   +-------------+--------------------+----------------------------------------------------------+
   | 401         | unauthorized       | Authentication failed.                                   |
   +-------------+--------------------+----------------------------------------------------------+
   | 403         | userDisabled       | You do not have the permission to perform the operation. |
   +-------------+--------------------+----------------------------------------------------------+
   | 404         | Not Found          | The requested page does not exist.                       |
   +-------------+--------------------+----------------------------------------------------------+
   | 500         | authFault          | System error.                                            |
   +-------------+--------------------+----------------------------------------------------------+
   | 503         | serviceUnavailable | The service is unavailable.                              |
   +-------------+--------------------+----------------------------------------------------------+

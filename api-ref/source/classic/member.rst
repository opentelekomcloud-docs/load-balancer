Backend ECS
###########

Adding Backend ECSs
===================

Function
^^^^^^^^

This API is used to add backend ECSs to a listener for monitoring.

To add backend ECSs to a UDP listener, IP addresses can be pinged and UDP services must be enabled.

URI
^^^

POST /v1.0/{project_id}/elbaas/listeners/{listener_id}/members

.. table:: **Table 1** Parameter description

   =========== ========= ====== ====================================================
   Parameter   Mandatory Type   Description
   =========== ========= ====== ====================================================
   project_id  Yes       String Specifies the project ID.
   listener_id Yes       String Specifies the listener ID.
   server_id   Yes       String Specifies the backend ECS ID.
   address     Yes       String Specifies the private IP address of the backend ECS.
   =========== ========= ====== ====================================================

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   .. code:: json

      [
          {
              "server_id": "dbecb618-2259-405f-ab17-9b68c4f541b0",
              "address": "172.16.0.31"
          }
      ]

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 2** Parameter description

   ========= ====== ======================================================================================
   Parameter Type   Description
   ========= ====== ======================================================================================
   uri       String Specifies the URI of the job for adding a backend ECS. It is returned by Combined API.
   job_id    String Specifies the unique ID assigned to the job for adding a backend ECS in Combined API.
   ========= ====== ======================================================================================

-  Example response

   .. code:: json

      {
          "uri": "/v1/55300f3c8f764c06b1a32e2302edc305/jobs/4010b39b4fd3d5ff014fd3ec3ed8002d",
          "job_id": "4010b39b4fd3d5ff014fd3ec3ed8002d"
      }

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

Removing Backend ECSs
=====================

Function
^^^^^^^^

This API is used to remove backend ECSs from a listener. Multiple backend ECSs can be removed concurrently.

URI
^^^

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
^^^^^^^

-  Request parameters

   None

-  Example request

   .. code:: json

      {
          "removeMember": [
              {
                  "id": "34695d664b182fa69b98228032b0e239"
              }
          ]
      }

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 3** Parameter description

   ========= ====== =================================================================================================
   Parameter Type   Description
   ========= ====== =================================================================================================
   uri       String Specifies the URI returned by Combined API after the job for removing a backend ECS is delivered.
   job_id    String Specifies the unique ID assigned to the job for removing a backend ECS in Combined API.
   ========= ====== =================================================================================================

-  Example response

   .. code:: json

      {
          "uri": "/v1/55300f3c8f764c06b1a32e2302edc305/jobs/4010b39b4fd3d5ff014fd3f160fd006c",
          "job_id": "4010b39b4fd3d5ff014fd3f160fd006c"
      }

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

Querying Backend ECSs
=====================

Function
^^^^^^^^

This API is used to query backend ECSs added to a listener. If you are the administrator, the backend ECS list will be empty.

URI
^^^

GET /v1.0/{project_id}/elbaas/listeners/{listener_id}/members?limit=10&marker=0

|image1|

Enter a question mark (?) and an ampersand (&) at the end of the URI to define multiple search criteria. This API allows filtering backend ECSs by each parameter in the response message except **listeners**, **server_name**, **update_time**, and **create_time**.

.. table:: **Table 1** Parameter description

   +-------------+-----------+---------+-------------------------------------------------------------------------+
   | Parameter   | Mandatory | Type    | Description                                                             |
   +=============+===========+=========+=========================================================================+
   | project_id  | Yes       | String  | Specifies the project ID.                                               |
   +-------------+-----------+---------+-------------------------------------------------------------------------+
   | listener_id | Yes       | String  | Specifies the listener ID.                                              |
   +-------------+-----------+---------+-------------------------------------------------------------------------+
   | marker      | No        | String  | Specifies the resource ID of pagination query. If the parameter is left |
   |             |           |         | blank, only resources on the first page are queried.                    |
   +-------------+-----------+---------+-------------------------------------------------------------------------+
   | limit       | No        | Integer | Specifies the number of records on each page.                           |
   +-------------+-----------+---------+-------------------------------------------------------------------------+

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   None

Response
^^^^^^^^

-  Response parameters

.. table:: **Table 2** Parameter description

   ============== ======== ================================================================================================
   Parameter      **Type** Description
   ============== ======== ================================================================================================
   server_address String   Specifies the private IP address of the backend ECS.
   id             String   Specifies the backend ECS ID.
   address        String   Specifies the floating IP address assigned to the backend ECS.
   status         String   Specifies the status of the backend ECS. The value can be **ACTIVE**, **PENDING**, or **ERROR**.
   health_status  String   Specifies the health check result. The value is **NORMAL**, **ABNORMAL**, or **UNAVAILABLE**.
   update_time    String   Specifies the time when the backend ECS was updated.
   create_time    String   Specifies the time when the backend ECS was added.
   server_name    String   Specifies the backend ECS name.
   server_id      String   Specifies the backend ECS ID.
   listeners      Array    Specifies the listener with which the backend ECS is associated.
   ============== ======== ================================================================================================

.. table:: **Table 3** **listeners** parameter description

   ========= ======== ================================================================
   Parameter **Type** Description
   ========= ======== ================================================================
   id        String   Specifies the listener with which the backend ECS is associated.
   ========= ======== ================================================================

-  Example response

   .. code:: json

      [
          {
              "server_address": "172.16.0.16",
              "id": "4ac8777333bc20777147ab160ea61baf",
              "status": "ACTIVE",
              "address": "100.64.27.96",
              "listeners": [
                  {
                      "id": "65093734fb966b3d70f6af26cc63e125"
                  },
                  {
                      "id": "a659fe780a542e1adf204db767a021a3"
                  }
              ],
              "update_time": "2015-12-28 10:35:51",
              "create_time": "2015-12-28 10:35:50",
              "server_name": null,
              "server_id": "97444148-7afb-47cc-b4a3-6e1c94d1ade4",
              "health_status": "NORMAL"
          },
          {
              "server_address": "172.16.0.15",
              "id": "d8a21f107a19d7bd1d05a1f764eb623a",
              "status": "ACTIVE",
              "address": "100.64.27.95",
              "listeners": [
                  {
                      "id": "65093734fb966b3d70f6af26cc63e125"
                  },
                  {
                      "id": "a659fe780a542e1adf204db767a021a3"
                  }
              ],
              "update_time": "2015-12-28 10:35:51",
              "create_time": "2015-12-28 10:35:50",
              "server_name": null,
              "server_id": "05b731db-d457-41dc-a824-862daba91a59",
              "health_status": "ABNORMAL"
          }
      ]

Status Code
^^^^^^^^^^^

-  Normal

   200

-  Error

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

.. |image1| image:: /media/image2.png

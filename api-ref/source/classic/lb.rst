Load Balancer
#############

Creating a Load Balancer
========================

Function
^^^^^^^^

This API is used to create a load balancer.

URI
^^^

POST /v1.0/{project_id}/elbaas/loadbalancers

.. table:: **Table 1** Parameter description

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

Request
^^^^^^^

-  Request parameters

   .. table:: **Table 2** Parameter description

      +-------------------+-----------+-----------------+-----------------------------+
      | Parameter         | Mandatory | Type            | Description                 |
      +===================+===========+=================+=============================+
      | name              | Yes       | String          | -  Specifies the load       |
      |                   |           |                 |    balancer name.           |
      |                   |           |                 | -  The value can contain 1  |
      |                   |           |                 |    to 64 characters that    |
      |                   |           |                 |    consist of letters,      |
      |                   |           |                 |    digits, underscores (_), |
      |                   |           |                 |    and hyphens (-).         |
      +-------------------+-----------+-----------------+-----------------------------+
      | description       | No        | String          | -  Provides supplementary   |
      |                   |           |                 |    information about the    |
      |                   |           |                 |    load balancer.           |
      |                   |           |                 | -  The value contains 0 to  |
      |                   |           |                 |    128 characters and       |
      |                   |           |                 |    cannot contain angle     |
      |                   |           |                 |    brackets (< and >).      |
      +-------------------+-----------+-----------------+-----------------------------+
      | vpc_id            | Yes       | String          | Specifies the VPC ID.       |
      +-------------------+-----------+-----------------+-----------------------------+
      | bandwidth         | No        | Integer         | -  Specifies the bandwidth  |
      |                   |           |                 |    (Mbit/s). This parameter |
      |                   |           |                 |    is mandatory when        |
      |                   |           |                 |    **type** is set to       |
      |                   |           |                 |    **External**.            |
      |                   |           |                 |                             |
      |                   |           |                 | -  The value ranges from    |
      |                   |           |                 |    **1** to **500**.        |
      |                   |           |                 |                             |
      |                   |           |                 |    (The specific range may  |
      |                   |           |                 |    vary depending on the    |
      |                   |           |                 |    configuration in each    |
      |                   |           |                 |    region. You can see the  |
      |                   |           |                 |    bandwidth range of each  |
      |                   |           |                 |    region on the management |
      |                   |           |                 |    console.)                |
      +-------------------+-----------+-----------------+-----------------------------+
      | type              | Yes       | String          | -  Specifies the network    |
      |                   |           |                 |    type of the load         |
      |                   |           |                 |    balancer.                |
      |                   |           |                 | -  The value is             |
      |                   |           |                 |    **Internal** or          |
      |                   |           |                 |    **External**.            |
      +-------------------+-----------+-----------------+-----------------------------+
      | admin_state_up    | Yes       | Integer/Boolean | -  Specifies the            |
      |                   |           |                 |    administrative status of |
      |                   |           |                 |    the load balancer.       |
      |                   |           |                 |                             |
      |                   |           |                 | -  Optional values:         |
      |                   |           |                 |                             |
      |                   |           |                 |    **0** or **false**:      |
      |                   |           |                 |    indicates that the load  |
      |                   |           |                 |    balancer is stopped.     |
      |                   |           |                 |    Only users are allowed   |
      |                   |           |                 |    to enter the two values. |
      |                   |           |                 |                             |
      |                   |           |                 |    **1** or **true**:       |
      |                   |           |                 |    indicates that the load  |
      |                   |           |                 |    balancer is running      |
      |                   |           |                 |    properly.                |
      |                   |           |                 |                             |
      |                   |           |                 |    **2** or **false**:      |
      |                   |           |                 |    indicates that the load  |
      |                   |           |                 |    balancer is frozen. Only |
      |                   |           |                 |    the administrator is     |
      |                   |           |                 |    allowed to enter the two |
      |                   |           |                 |    values.                  |
      +-------------------+-----------+-----------------+-----------------------------+
      | vip_subnet_id     | No        | String          | Specifies the subnet ID of  |
      |                   |           |                 | backend ECSs. This          |
      |                   |           |                 | parameter is mandatory when |
      |                   |           |                 | **type** is set to          |
      |                   |           |                 | **Internal**. Only IPv4     |
      |                   |           |                 | subnets can be specified.   |
      +-------------------+-----------+-----------------+-----------------------------+
      | az                | No        | String          | Specifies the AZ of the     |
      |                   |           |                 | load balancer. This         |
      |                   |           |                 | parameter is invalid when   |
      |                   |           |                 | type is set to **External** |
      |                   |           |                 | and is optional when type   |
      |                   |           |                 | is set to **Internal**. If  |
      |                   |           |                 | **type** is set to          |
      |                   |           |                 | **Internal** and an AZ is   |
      |                   |           |                 | specified, the specified AZ |
      |                   |           |                 | must support private        |
      |                   |           |                 | network load balancers.     |
      |                   |           |                 | Otherwise, an error message |
      |                   |           |                 | is returned. For more       |
      |                   |           |                 | details, see `Regions and   |
      |                   |           |                 | Endpoints <https:/          |
      |                   |           |                 | /docs.otc.t-systems.com/en- |
      |                   |           |                 | us/endpoint/index.html>`__. |
      +-------------------+-----------+-----------------+-----------------------------+
      | charge_mode       | No        | String          | -  Specifies how a new      |
      |                   |           |                 |    elastic IP address (EIP) |
      |                   |           |                 |    is billed. This is a     |
      |                   |           |                 |    reserved parameter. If   |
      |                   |           |                 |    the system supports      |
      |                   |           |                 |    billing by traffic and   |
      |                   |           |                 |    this parameter is        |
      |                   |           |                 |    specified, the EIP will  |
      |                   |           |                 |    be billed by traffic.    |
      |                   |           |                 | -  Specifies whether the    |
      |                   |           |                 |    EIP is billed by traffic |
      |                   |           |                 |    or fixed bandwidth. If   |
      |                   |           |                 |    this parameter is left   |
      |                   |           |                 |    blank or incorrectly     |
      |                   |           |                 |    set, the EIP is billed   |
      |                   |           |                 |    by traffic by default.   |
      |                   |           |                 | -  The value is             |
      |                   |           |                 |    **traffic**.             |
      +-------------------+-----------+-----------------+-----------------------------+
      | eip_type          | No        | String          | -  This parameter is        |
      |                   |           |                 |    reserved.                |
      +-------------------+-----------+-----------------+-----------------------------+
      | security_group_id | No        | String          | -  Specifies the security   |
      |                   |           |                 |    group ID.                |
      |                   |           |                 | -  The value can contain 1  |
      |                   |           |                 |    to 200 characters that   |
      |                   |           |                 |    consists of letters,     |
      |                   |           |                 |    digits, and hyphens (-). |
      |                   |           |                 | -  This parameter is        |
      |                   |           |                 |    mandatory if the value   |
      |                   |           |                 |    of **type** is           |
      |                   |           |                 |    **Internal**, while it   |
      |                   |           |                 |    is ignored when the      |
      |                   |           |                 |    value of **type** is     |
      |                   |           |                 |    **External**.            |
      +-------------------+-----------+-----------------+-----------------------------+
      | vip_address       | No        | String          | -  Specifies the private IP |
      |                   |           |                 |    address of the load      |
      |                   |           |                 |    balancer. When **type**  |
      |                   |           |                 |    is set to **External**,  |
      |                   |           |                 |    the parameter value is   |
      |                   |           |                 |    the EIP. When **type**   |
      |                   |           |                 |    is set to **Internal**,  |
      |                   |           |                 |    the parameter value is   |
      |                   |           |                 |    the private network IP   |
      |                   |           |                 |    address.                 |
      |                   |           |                 | -  You can select an        |
      |                   |           |                 |    existing EIP to create a |
      |                   |           |                 |    public network load      |
      |                   |           |                 |    balancer. When this      |
      |                   |           |                 |    parameter is configured, |
      |                   |           |                 |    parameters               |
      |                   |           |                 |    **bandwidth**,           |
      |                   |           |                 |    **charge_mode**, and     |
      |                   |           |                 |    **eip_type** are         |
      |                   |           |                 |    invalid.                 |
      +-------------------+-----------+-----------------+-----------------------------+
      | tenantId          | No        | String          | -  Specifies the project    |
      |                   |           |                 |    ID.                      |
      |                   |           |                 | -  This parameter is        |
      |                   |           |                 |    mandatory when **type**  |
      |                   |           |                 |    is set to **Internal**.  |
      +-------------------+-----------+-----------------+-----------------------------+

-  Example request 1

   .. code:: json

      {
          "name": "loadbalancer1",
          "description": "simple lb",
          "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
          "bandwidth": 200,
          "type": "External",
          "admin_state_up": true
      }

-  Example request 2

   .. code:: json

      {
          "name": "loadbalancer1",
          "description": "simple lb",
          "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
          "vip_address": "192.144.164.74",
          "type": "External",
          "admin_state_up": true
      }

Response
^^^^^^^^

-  Response parameters

   .. table:: **Table 3** Parameter description

      ========= ====== ===================================================================================================
      Parameter Type   Description
      ========= ====== ===================================================================================================
      uri       String Specifies the URI returned by Combined API after the job for creating a load balancer is delivered.
      job_id    String Specifies the unique ID assigned to the job for creating a load balancer in Combined API.
      ========= ====== ===================================================================================================

-  Example response

   .. code:: json

      {
          "uri": "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39b4fbb4645014fcfc8f2d178d1",
          "job_id": "4010b39b4fbb4645014fcfc8f2d178d1"
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

Deleting a Load Balancer
========================

Function
^^^^^^^^

This API is used to delete a load balancer. If the load balancer is a public network load balancer, this API deletes the EIP bound to the load balancer.

Constraints
^^^^^^^^^^^

For a public network load balancer, you need to delete the backend ECSs added to all listeners of the load balancer before deleting it.

URI
^^^

DELETE /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ========= ====== ===============================
   Parameter       Mandatory Type   Description
   =============== ========= ====== ===============================
   project_id      Yes       String Specifies the project ID.
   loadbalancer_id Yes       String Specifies the load balancer ID.
   =============== ========= ====== ===============================

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

      ========= ====== ===================================================================================================
      Parameter Type   Description
      ========= ====== ===================================================================================================
      uri       String Specifies the URI returned by Combined API after
                       the job for deleting a load balancer is delivered.
      job_id    String Specifies the unique ID assigned to the job for
                       deleting a load balancer in Combined API.
      ========= ====== ===================================================================================================

-  Example response

   .. code:: json

      {
          "uri": "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39c4fbb4649014fcfd2ab7903b0",
          "job_id": "4010b39c4fbb4649014fcfd2ab7903b0"
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

Deleting a Public Network Load Balancer
=======================================

Function
^^^^^^^^

This API is used to delete a public network load balancer. The EIP bound to the load balancer will not be deleted. If you need to delete this IP address, refer to `Deleting a Load Balancer <elb_jd_fz_0002.html#elb_jd_fz_0002>`__.

Constraints
^^^^^^^^^^^

Before deleting a public network load balancer, you must remove all backend ECSs from the listener. This API cannot be used to delete a private network load balancer.

URI
^^^

DELETE /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}/keep-eip

.. table:: **Table 1** Parameter description

   =============== ============= ======== ===============================
   Parameter       **Mandatory** **Type** Description
   =============== ============= ======== ===============================
   project_id      Yes           String   Specifies the project ID.
   loadbalancer_id Yes           String   Specifies the load balancer ID.
   =============== ============= ======== ===============================

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

      ========= ======== ===================================================================================================
      Parameter **Type** Description
      ========= ======== ===================================================================================================
      uri       String   Specifies the URI returned by Combined API after the job for deleting a load balancer is delivered.
      job_id    String   Specifies the unique ID assigned to the job for deleting a load balancer in Combined API.
      ========= ======== ===================================================================================================

-  Example response

   .. code:: json

      {
          "uri": "/v1/8263303061de4b5d95c9cb68c3a257f4/jobs/ff808082615b23aa01616b90efc65298",
          "job_id": "ff808082615b23aa01616b90efc65298"
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
   403         userDisable        You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          System error.
   503         serviceUnavailable The service is unavailable.
   =========== ================== ========================================================

Modifying a Load Balancer
=========================

Function
^^^^^^^^

This API is used to modify the name, description, bandwidth, and administrative status of a load balancer.

URI
^^^

PUT /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | Parameter                   | Mandatory                   | Type                        | Description                 |
   +=============================+=============================+=============================+=============================+
   | project_id                  | Yes                         | String                      | Specifies the project ID.   |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | loadbalancer_id             | Yes                         | String                      | Specifies the load balancer |
   |                             |                             |                             | ID.                         |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | name                        | No                          | String                      | -  Specifies the load       |
   |                             |                             |                             |    balancer name.           |
   |                             |                             |                             | -  The value can contain 1  |
   |                             |                             |                             |    to 64 characters that    |
   |                             |                             |                             |    consist of letters,      |
   |                             |                             |                             |    digits, underscores (_), |
   |                             |                             |                             |    and hyphens (-).         |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | description                 | No                          | String                      | -  Provides supplementary   |
   |                             |                             |                             |    information about the    |
   |                             |                             |                             |    load balancer.           |
   |                             |                             |                             | -  The value contains 0 to  |
   |                             |                             |                             |    128 characters and       |
   |                             |                             |                             |    cannot contain angle     |
   |                             |                             |                             |    brackets (< and >).      |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | bandwidth                   | No                          | Integer                     | -  Specifies the bandwidth  |
   |                             |                             |                             |    (Mbit/s). This parameter |
   |                             |                             |                             |    is mandatory when        |
   |                             |                             |                             |    **type** is set to       |
   |                             |                             |                             |    **External**.            |
   |                             |                             |                             |                             |
   |                             |                             |                             | -  The value ranges from 1  |
   |                             |                             |                             |    to 500.                  |
   |                             |                             |                             |                             |
   |                             |                             |                             |    (The specific range may  |
   |                             |                             |                             |    vary depending on the    |
   |                             |                             |                             |    configuration in each    |
   |                             |                             |                             |    region. You can see the  |
   |                             |                             |                             |    bandwidth range of each  |
   |                             |                             |                             |    region on the management |
   |                             |                             |                             |    console.)                |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+
   | admin_state_up              | No                          | Integer/Boolean             | -  Specifies the            |
   |                             |                             |                             |    administrative status of |
   |                             |                             |                             |    the load balancer.       |
   |                             |                             |                             |                             |
   |                             |                             |                             | -  Optional values:         |
   |                             |                             |                             |                             |
   |                             |                             |                             |    **0** or **false**:      |
   |                             |                             |                             |    indicates that the load  |
   |                             |                             |                             |    balancer is stopped.     |
   |                             |                             |                             |    Only users are allowed   |
   |                             |                             |                             |    to enter the two values. |
   |                             |                             |                             |                             |
   |                             |                             |                             |    **1** or **true**:       |
   |                             |                             |                             |    indicates that the load  |
   |                             |                             |                             |    balancer is running      |
   |                             |                             |                             |    properly.                |
   |                             |                             |                             |                             |
   |                             |                             |                             |    **2** or **false**:      |
   |                             |                             |                             |    indicates that the load  |
   |                             |                             |                             |    balancer is frozen. Only |
   |                             |                             |                             |    the administrator is     |
   |                             |                             |                             |    allowed to enter the two |
   |                             |                             |                             |    values.                  |
   +-----------------------------+-----------------------------+-----------------------------+-----------------------------+

Request
^^^^^^^

-  Request parameters

   None

-  Example request

   .. code:: json

      {
          "description": "simple lb",
          "name": "loadbalancer1",
          "bandwidth": 200,
          "admin_state_up": true
      }

Response
^^^^^^^^

-  Response parameters

   .. table:: **Table 2** Parameter description

      ========= ====== ====================================================================================================
      Parameter Type   Description
      ========= ====== ====================================================================================================
      uri       String Specifies the URI returned by Combined API after the job for modifying a load balancer is delivered.
      job_id    String Specifies the unique ID assigned to the job for modifying a load balancer in Combined API.
      ========= ====== ====================================================================================================

-  Example response

   .. code:: json

      {
          "uri": "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39d4fbb4645014fcfddf4b32d15",
          "job_id": "4010b39d4fbb4645014fcfddf4b32d15"
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

Querying Details of a Load Balancer
===================================

Function
^^^^^^^^

This API is used to query details about a load balancer.

URI
^^^

GET /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

.. table:: **Table 1** Parameter description

   =============== ============= ======== ===============================
   Parameter       **Mandatory** **Type** Description
   =============== ============= ======== ===============================
   project_id      Yes           String   Specifies the project ID.
   loadbalancer_id Yes           String   Specifies the load balancer ID.
   =============== ============= ======== ===============================

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

      +-------------------+---------+--------------------------------------+
      | Parameter         | Type    | Description                          |
      +===================+=========+======================================+
      | vip_address       | String  | Specifies the private IP address of  |
      |                   |         | the load balancer.                   |
      +-------------------+---------+--------------------------------------+
      | update_time       | String  | Specifies the time when the load     |
      |                   |         | balancer was updated.                |
      +-------------------+---------+--------------------------------------+
      | create_time       | String  | Specifies the time when the load     |
      |                   |         | balancer was created.                |
      +-------------------+---------+--------------------------------------+
      | id                | String  | Specifies the load balancer ID.      |
      +-------------------+---------+--------------------------------------+
      | status            | String  | -  Specifies the load balancer       |
      |                   |         |    status.                           |
      |                   |         | -  The value can be **ACTIVE**,      |
      |                   |         |    **PENDING_CREATE**, or **ERROR**. |
      +-------------------+---------+--------------------------------------+
      | bandwidth         | Integer | Specifies the bandwidth (Mbit/s).    |
      +-------------------+---------+--------------------------------------+
      | vpc_id            | String  | Specifies the VPC ID.                |
      +-------------------+---------+--------------------------------------+
      | admin_state_up    | Integer | -  Specifies the administrative      |
      |                   |         |    status of the load balancer.      |
      |                   |         |                                      |
      |                   |         | -  The following options are         |
      |                   |         |    available:                        |
      |                   |         |                                      |
      |                   |         |    **0**: The load balancer is       |
      |                   |         |    disabled.                         |
      |                   |         |                                      |
      |                   |         |    **1**: The load balancer is       |
      |                   |         |    running properly.                 |
      |                   |         |                                      |
      |                   |         |    **2**: The load balancer is       |
      |                   |         |    frozen.                           |
      +-------------------+---------+--------------------------------------+
      | vip_subnet_id     | String  | This parameter is unavailable now.   |
      +-------------------+---------+--------------------------------------+
      | type              | String  | Specifies the network type of the    |
      |                   |         | load balancer. The value is          |
      |                   |         | **External**.                        |
      +-------------------+---------+--------------------------------------+
      | name              | String  | Specifies the load balancer name.    |
      +-------------------+---------+--------------------------------------+
      | description       | String  | Provides supplementary information   |
      |                   |         | about the load balancer.             |
      +-------------------+---------+--------------------------------------+
      | security_group_id | String  | -  Specifies the security group ID.  |
      |                   |         | -  **null** is displayed for this    |
      |                   |         |    parameter when **type** is set to |
      |                   |         |    **External**.                     |
      +-------------------+---------+--------------------------------------+

-  Example response

   .. code:: json

      {
          "vip_address": "192.144.62.114",
          "update_time": "2015-09-14 02:34:32",
          "create_time": "2015-09-14 02:34:32",
          "id": "0b07acf06d243925bc24a0ac7445267a",
          "status": "ACTIVE",
          "bandwidth": 1,
          "security_group_id": null,
          "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
          "admin_state_up": 1,
          "vip_subnet_id": null,
          "type": "External",
          "name": "MY_ELB",
          "description": null
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

Querying Load Balancers
=======================

Function
^^^^^^^^

This API is used to query load balancers and display them in a list.

URI
^^^

GET /v1.0/{project_id}/elbaas/loadbalancers

.. table:: **Table 1** Parameter description

   ========== ========= ====== =========================
   Parameter  Mandatory Type   Description
   ========== ========= ====== =========================
   project_id Yes       String Specifies the project ID.
   ========== ========= ====== =========================

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

      ============= ====== =======================================
      Parameter     Type   Description
      ============= ====== =======================================
      loadbalancers Array  Lists the load balancers.
      instance_num  String Specifies the number of load balancers.
      ============= ====== =======================================

   .. table:: **Table 3** **loadbalancers** parameter description

      +-------------------+---------+--------------------------------------+
      | Parameter         | Type    | Description                          |
      +===================+=========+======================================+
      | vip_address       | String  | Specifies the private IP address of  |
      |                   |         | the load balancer.                   |
      +-------------------+---------+--------------------------------------+
      | update_time       | String  | Specifies the time when the listener |
      |                   |         | was updated.                         |
      +-------------------+---------+--------------------------------------+
      | create_time       | String  | Specifies the time when the listener |
      |                   |         | was created.                         |
      +-------------------+---------+--------------------------------------+
      | id                | String  | Specifies the load balancer ID.      |
      +-------------------+---------+--------------------------------------+
      | status            | String  | -  Specifies the load balancer       |
      |                   |         |    status.                           |
      |                   |         | -  The value can be **ACTIVE**,      |
      |                   |         |    **PENDING_CREATE**, or **ERROR**. |
      +-------------------+---------+--------------------------------------+
      | bandwidth         | Integer | Specifies the bandwidth.             |
      +-------------------+---------+--------------------------------------+
      | vpc_id            | String  | Specifies the VPC ID.                |
      +-------------------+---------+--------------------------------------+
      | admin_state_up    | Integer | -  Specifies the administrative      |
      |                   |         |    status of the load balancer.      |
      |                   |         |                                      |
      |                   |         | -  The value options are as follows: |
      |                   |         |                                      |
      |                   |         |    **0**: The load balancer is       |
      |                   |         |    disabled.                         |
      |                   |         |                                      |
      |                   |         |    **1**: The load balancer is       |
      |                   |         |    running properly.                 |
      |                   |         |                                      |
      |                   |         |    **2**: The load balancer is       |
      |                   |         |    frozen.                           |
      +-------------------+---------+--------------------------------------+
      | vip_subnet_id     | String  | This parameter is unavailable now.   |
      +-------------------+---------+--------------------------------------+
      | type              | String  | Specifies the network type of the    |
      |                   |         | load balancer. The value is          |
      |                   |         | **External**.                        |
      +-------------------+---------+--------------------------------------+
      | name              | String  | Specifies the load balancer name.    |
      +-------------------+---------+--------------------------------------+
      | description       | String  | Description                          |
      +-------------------+---------+--------------------------------------+
      | security_group_id | String  | -  Specifies the security group ID.  |
      |                   |         | -  **null** is displayed for this    |
      |                   |         |    parameter when **type** is set to |
      |                   |         |    **External**.                     |
      +-------------------+---------+--------------------------------------+

-  Example response

   .. code:: json

      {
          "loadbalancers": [
              {
                  "vip_address": "192.144.62.114",
                  "update_time": "2015-09-14 02:34:32",
                  "create_time": "2015-09-14 02:34:32",
                  "id": "0b07acf06d243925bc24a0ac7445267a",
                  "status": "ACTIVE",
                  "bandwidth": 1,
                  "security_group_id": null,
                  "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
                  "admin_state_up": 1,
                  "vip_subnet_id": null,
                  "type": "External",
                  "name": "MY_ELB",
                  "description": null
              }
          ],
          "instance_num": "1"
      }

Status Codes
^^^^^^^^^^^^

-  Normal

   200

-  Abnormal

   =========== ================== ========================================================
   Status Code Message            Description
   =========== ================== ========================================================
   400         badRequest         Request error.
   401         unauthorized       Authentication failed.
   403         userDisabled       You do not have the permission to perform the operation.
   404         Not Found          The requested page does not exist.
   500         authFault          Internal error.
   503         serviceUnavailable Service unavailable.
   =========== ================== ========================================================

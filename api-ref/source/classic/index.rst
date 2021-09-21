Classic Load Balancer APIs
==========================

API Call Precaution
-------------------

Classic load balancers are not supported in the **eu-nl** region.

Load Balancer
-------------

1. .. rubric:: Creating a Load Balancer
      :name: creating-a-load-balancer

   #. Function

This API is used to create a load balancer.

2. URI

POST /v1.0/{project_id}/elbaas/loadbalancers

1. Parameter description

+---------------------+-------------+------------+---------------------+
| Parameter           | Mandatory   | Type       | Description         |
+=====================+=============+============+=====================+
| project_id          | Yes         | String     | Specifies the       |
|                     |             |            | project ID.         |
+---------------------+-------------+------------+---------------------+

3. Request

-  Request parameters

   1. Parameter description

+---------------------+-------------+---------+------------------------+
| Parameter           | Mandatory   | Type    | Description            |
+=====================+=============+=========+========================+
| name                | Yes         | String  | -  Specifies the load  |
|                     |             |         |    balancer name.      |
|                     |             |         |                        |
|                     |             |         | -  The value can       |
|                     |             |         |    contain 1 to 64     |
|                     |             |         |    characters that     |
|                     |             |         |    consist of letters, |
|                     |             |         |    digits, underscores |
|                     |             |         |    (_), and hyphens    |
|                     |             |         |    (-).                |
+---------------------+-------------+---------+------------------------+
| description         | No          | String  | -  Provides            |
|                     |             |         |    supplementary       |
|                     |             |         |    information about   |
|                     |             |         |    the load balancer.  |
|                     |             |         |                        |
|                     |             |         | -  The value contains  |
|                     |             |         |    0 to 128 characters |
|                     |             |         |    and cannot contain  |
|                     |             |         |    angle brackets (<   |
|                     |             |         |    and >).             |
+---------------------+-------------+---------+------------------------+
| vpc_id              | Yes         | String  | Specifies the VPC ID.  |
+---------------------+-------------+---------+------------------------+
| bandwidth           | No          | Integer | -  Specifies the       |
|                     |             |         |    bandwidth (Mbit/s). |
|                     |             |         |    This parameter is   |
|                     |             |         |    mandatory when      |
|                     |             |         |    **type** is set to  |
|                     |             |         |    **External**.       |
|                     |             |         |                        |
|                     |             |         | -  The value ranges    |
|                     |             |         |    from **1** to       |
|                     |             |         |    **500**.            |
|                     |             |         |                        |
|                     |             |         | (The specific range    |
|                     |             |         | may vary depending on  |
|                     |             |         | the configuration in   |
|                     |             |         | each region. You can   |
|                     |             |         | see the bandwidth      |
|                     |             |         | range of each region   |
|                     |             |         | on the management      |
|                     |             |         | console.)              |
+---------------------+-------------+---------+------------------------+
| type                | Yes         | String  | -  Specifies the       |
|                     |             |         |    network type of the |
|                     |             |         |    load balancer.      |
|                     |             |         |                        |
|                     |             |         | -  The value is        |
|                     |             |         |    **Internal** or     |
|                     |             |         |    **External**.       |
+---------------------+-------------+---------+------------------------+
| admin_state_up      | Yes         | I       | -  Specifies the       |
|                     |             | nteger/ |    administrative      |
|                     |             | Boolean |    status of the load  |
|                     |             |         |    balancer.           |
|                     |             |         |                        |
|                     |             |         | -  Optional values:    |
|                     |             |         |                        |
|                     |             |         | **0** or **false**:    |
|                     |             |         | indicates that the     |
|                     |             |         | load balancer is       |
|                     |             |         | stopped. Only users    |
|                     |             |         | are allowed to enter   |
|                     |             |         | the two values.        |
|                     |             |         |                        |
|                     |             |         | **1** or **true**:     |
|                     |             |         | indicates that the     |
|                     |             |         | load balancer is       |
|                     |             |         | running properly.      |
|                     |             |         |                        |
|                     |             |         | **2** or **false**:    |
|                     |             |         | indicates that the     |
|                     |             |         | load balancer is       |
|                     |             |         | frozen. Only the       |
|                     |             |         | administrator is       |
|                     |             |         | allowed to enter the   |
|                     |             |         | two values.            |
+---------------------+-------------+---------+------------------------+
| vip_subnet_id       | No          | String  | Specifies the subnet   |
|                     |             |         | ID of backend ECSs.    |
|                     |             |         | This parameter is      |
|                     |             |         | mandatory when         |
|                     |             |         | **type** is set to     |
|                     |             |         | **Internal**. Only     |
|                     |             |         | IPv4 subnets can be    |
|                     |             |         | specified.             |
+---------------------+-------------+---------+------------------------+
| az                  | No          | String  | Specifies the AZ of    |
|                     |             |         | the load balancer.     |
|                     |             |         | This parameter is      |
|                     |             |         | invalid when type is   |
|                     |             |         | set to **External**    |
|                     |             |         | and is optional when   |
|                     |             |         | type is set to         |
|                     |             |         | **Internal**. If       |
|                     |             |         | **type** is set to     |
|                     |             |         | **Internal** and an AZ |
|                     |             |         | is specified, the      |
|                     |             |         | specified AZ must      |
|                     |             |         | support private        |
|                     |             |         | network load           |
|                     |             |         | balancers. Otherwise,  |
|                     |             |         | an error message is    |
|                     |             |         | returned. For more     |
|                     |             |         | details, see `Regions  |
|                     |             |         | and                    |
|                     |             |         | Endpoi                 |
|                     |             |         | nts <https://docs.otc. |
|                     |             |         | t-systems.com/en-us/en |
|                     |             |         | dpoint/index.html>`__. |
+---------------------+-------------+---------+------------------------+
| charge_mode         | No          | String  | -  Specifies how a new |
|                     |             |         |    elastic IP address  |
|                     |             |         |    (EIP) is billed.    |
|                     |             |         |    This is a reserved  |
|                     |             |         |    parameter. If the   |
|                     |             |         |    system supports     |
|                     |             |         |    billing by traffic  |
|                     |             |         |    and this parameter  |
|                     |             |         |    is specified, the   |
|                     |             |         |    EIP will be billed  |
|                     |             |         |    by traffic.         |
|                     |             |         |                        |
|                     |             |         | -  Specifies whether   |
|                     |             |         |    the EIP is billed   |
|                     |             |         |    by traffic or fixed |
|                     |             |         |    bandwidth. If this  |
|                     |             |         |    parameter is left   |
|                     |             |         |    blank or            |
|                     |             |         |    incorrectly set,    |
|                     |             |         |    the EIP is billed   |
|                     |             |         |    by traffic by       |
|                     |             |         |    default.            |
|                     |             |         |                        |
|                     |             |         | -  The value is        |
|                     |             |         |    **traffic**.        |
+---------------------+-------------+---------+------------------------+
| eip_type            | No          | String  | -  This parameter is   |
|                     |             |         |    reserved.           |
+---------------------+-------------+---------+------------------------+
| security_group_id   | No          | String  | -  Specifies the       |
|                     |             |         |    security group ID.  |
|                     |             |         |                        |
|                     |             |         | -  The value can       |
|                     |             |         |    contain 1 to 200    |
|                     |             |         |    characters that     |
|                     |             |         |    consists of         |
|                     |             |         |    letters, digits,    |
|                     |             |         |    and hyphens (-).    |
|                     |             |         |                        |
|                     |             |         | -  This parameter is   |
|                     |             |         |    mandatory if the    |
|                     |             |         |    value of **type**   |
|                     |             |         |    is **Internal**,    |
|                     |             |         |    while it is ignored |
|                     |             |         |    when the value of   |
|                     |             |         |    **type** is         |
|                     |             |         |    **External**.       |
+---------------------+-------------+---------+------------------------+
| vip_address         | No          | String  | -  Specifies the       |
|                     |             |         |    private IP address  |
|                     |             |         |    of the load         |
|                     |             |         |    balancer. When      |
|                     |             |         |    **type** is set to  |
|                     |             |         |    **External**, the   |
|                     |             |         |    parameter value is  |
|                     |             |         |    the EIP. When       |
|                     |             |         |    **type** is set to  |
|                     |             |         |    **Internal**, the   |
|                     |             |         |    parameter value is  |
|                     |             |         |    the private network |
|                     |             |         |    IP address.         |
|                     |             |         |                        |
|                     |             |         | -  You can select an   |
|                     |             |         |    existing EIP to     |
|                     |             |         |    create a public     |
|                     |             |         |    network load        |
|                     |             |         |    balancer. When this |
|                     |             |         |    parameter is        |
|                     |             |         |    configured,         |
|                     |             |         |    parameters          |
|                     |             |         |    **bandwidth**,      |
|                     |             |         |    **charge_mode**,    |
|                     |             |         |    and **eip_type**    |
|                     |             |         |    are invalid.        |
+---------------------+-------------+---------+------------------------+
| tenantId            | No          | String  | -  Specifies the       |
|                     |             |         |    project ID.         |
|                     |             |         |                        |
|                     |             |         | -  This parameter is   |
|                     |             |         |    mandatory when      |
|                     |             |         |    **type** is set to  |
|                     |             |         |    **Internal**.       |
+---------------------+-------------+---------+------------------------+

-  Example request 1

| {
| "name": "loadbalancer1",
| "description": "simple lb",
| "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
| "bandwidth": 200,
| "type": "External",
| "admin_state_up": true
| }

-  Example request 2

| {
| "name": "loadbalancer1",
| "description": "simple lb",
| "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
| "vip_address": "192.144.164.74",
| "type": "External",
| "admin_state_up": true
| }

#. Response

-  Response parameters

   1. Parameter description

+-----------------+-----------------+----------------------------------+
| Parameter       | Type            | Description                      |
+=================+=================+==================================+
| uri             | String          | Specifies the URI returned by    |
|                 |                 | Combined API after the job for   |
|                 |                 | creating a load balancer is      |
|                 |                 | delivered.                       |
+-----------------+-----------------+----------------------------------+
| job_id          | String          | Specifies the unique ID assigned |
|                 |                 | to the job for creating a load   |
|                 |                 | balancer in Combined API.        |
+-----------------+-----------------+----------------------------------+

-  Example response

| {
| "uri":
  "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39b4fbb4645014fcfc8f2d178d1",
| "job_id": "4010b39b4fbb4645014fcfc8f2d178d1"
| }

#. Status Code

-  Normal

200

-  Error

+---------+--------------------------+--------------------------------+
| Status  | Message                  | Description                    |
| Code    |                          |                                |
+=========+==========================+================================+
| 400     | badRequest               | Request error.                 |
+---------+--------------------------+--------------------------------+
| 401     | unauthorized             | Authentication failed.         |
+---------+--------------------------+--------------------------------+
| 403     | userDisabled             | You do not have the permission |
|         |                          | to perform the operation.      |
+---------+--------------------------+--------------------------------+
| 404     | Not Found                | The requested page does not    |
|         |                          | exist.                         |
+---------+--------------------------+--------------------------------+
| 500     | authFault                | System error.                  |
+---------+--------------------------+--------------------------------+
| 503     | serviceUnavailable       | The service is unavailable.    |
+---------+--------------------------+--------------------------------+

Deleting a Load Balancer
~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to delete a load balancer. If the load balancer is a
public network load balancer, this API deletes the EIP bound to the load
balancer.

2. Constraints

For a public network load balancer, you need to delete the backend ECSs
added to all listeners of the load balancer before deleting it.

3. URI

DELETE /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

1. Parameter description

+---------+-------------+------------+--------------------------------+
| Pa      | Mandatory   | Type       | Description                    |
| rameter |             |            |                                |
+=========+=============+============+================================+
| pro     | Yes         | String     | Specifies the project ID.      |
| ject_id |             |            |                                |
+---------+-------------+------------+--------------------------------+
| l       | Yes         | String     | Specifies the load balancer    |
| oadbala |             |            | ID.                            |
| ncer_id |             |            |                                |
+---------+-------------+------------+--------------------------------+

4. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------+--------------+--------------------------------------------+
| Pa      | Type         | Description                                |
| rameter |              |                                            |
+=========+==============+============================================+
| uri     | String       | Specifies the URI returned by Combined API |
|         |              | after the job for deleting a load balancer |
|         |              | is delivered.                              |
+---------+--------------+--------------------------------------------+
| job_id  | String       | Specifies the unique ID assigned to the    |
|         |              | job for deleting a load balancer in        |
|         |              | Combined API.                              |
+---------+--------------+--------------------------------------------+

-  Example response

| {
| "uri":
  "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39c4fbb4649014fcfd2ab7903b0",
| "job_id": "4010b39c4fbb4649014fcfd2ab7903b0"
| }

#. Status Code

-  Normal

200

-  Error

+--------+----------------------------+--------------------------------+
| Status | Message                    | Description                    |
| Code   |                            |                                |
+========+============================+================================+
| 400    | badRequest                 | Request error.                 |
+--------+----------------------------+--------------------------------+
| 401    | unauthorized               | Authentication failed.         |
+--------+----------------------------+--------------------------------+
| 403    | userDisabled               | You do not have the permission |
|        |                            | to perform the operation.      |
+--------+----------------------------+--------------------------------+
| 404    | Not Found                  | The requested page does not    |
|        |                            | exist.                         |
+--------+----------------------------+--------------------------------+
| 500    | authFault                  | System error.                  |
+--------+----------------------------+--------------------------------+
| 503    | serviceUnavailable         | The service is unavailable.    |
+--------+----------------------------+--------------------------------+

Deleting a Public Network Load Balancer
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to delete a public network load balancer. The EIP bound
to the load balancer will not be deleted. If you need to delete this IP
address, refer to `Deleting a Load
Balancer <#deleting-a-load-balancer>`__.

2. Constraints

Before deleting a public network load balancer, you must remove all
backend ECSs from the listener. This API cannot be used to delete a
private network load balancer.

3. URI

DELETE
/v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}/keep-eip

1. Parameter description

+----------------+----------------+-----------------+-----------------+
| Parameter      | Mandatory      | Type            | Description     |
+================+================+=================+=================+
| project_id     | Yes            | String          | Specifies the   |
|                |                |                 | project ID.     |
+----------------+----------------+-----------------+-----------------+
| l              | Yes            | String          | Specifies the   |
| oadbalancer_id |                |                 | load balancer   |
|                |                |                 | ID.             |
+----------------+----------------+-----------------+-----------------+

4. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+-----------------------+-----------------------+-----------------------+
| Parameter             | Type                  | Description           |
+=======================+=======================+=======================+
| uri                   | String                | Specifies the URI     |
|                       |                       | returned by Combined  |
|                       |                       | API after the job for |
|                       |                       | deleting a load       |
|                       |                       | balancer is           |
|                       |                       | delivered.            |
+-----------------------+-----------------------+-----------------------+
| job_id                | String                | Specifies the unique  |
|                       |                       | ID assigned to the    |
|                       |                       | job for deleting a    |
|                       |                       | load balancer in      |
|                       |                       | Combined API.         |
+-----------------------+-----------------------+-----------------------+

-  Example response

| {
| "uri":
  "/v1/8263303061de4b5d95c9cb68c3a257f4/jobs/ff808082615b23aa01616b90efc65298",
| "job_id": "ff808082615b23aa01616b90efc65298"
| }

#. Status Code

-  Normal

200

-  Error

+--------+----------------------------+--------------------------------+
| Status | Message                    | Description                    |
| Code   |                            |                                |
+========+============================+================================+
| 400    | badRequest                 | Request error.                 |
+--------+----------------------------+--------------------------------+
| 401    | unauthorized               | Authentication failed.         |
+--------+----------------------------+--------------------------------+
| 403    | userDisable                | You do not have the permission |
|        |                            | to perform the operation.      |
+--------+----------------------------+--------------------------------+
| 404    | Not Found                  | The requested page does not    |
|        |                            | exist.                         |
+--------+----------------------------+--------------------------------+
| 500    | authFault                  | System error.                  |
+--------+----------------------------+--------------------------------+
| 503    | serviceUnavailable         | The service is unavailable.    |
+--------+----------------------------+--------------------------------+

Modifying a Load Balancer
~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to modify the name, description, bandwidth, and
administrative status of a load balancer.

2. URI

PUT /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

1. Parameter description

+---------------------+-----------+------------+-----------------------+
| Parameter           | Mandatory | Type       | Description           |
+=====================+===========+============+=======================+
| project_id          | Yes       | String     | Specifies the project |
|                     |           |            | ID.                   |
+---------------------+-----------+------------+-----------------------+
| loadbalancer_id     | Yes       | String     | Specifies the load    |
|                     |           |            | balancer ID.          |
+---------------------+-----------+------------+-----------------------+
| name                | No        | String     | -  Specifies the load |
|                     |           |            |    balancer name.     |
|                     |           |            |                       |
|                     |           |            | -  The value can      |
|                     |           |            |    contain 1 to 64    |
|                     |           |            |    characters that    |
|                     |           |            |    consist of         |
|                     |           |            |    letters, digits,   |
|                     |           |            |    underscores (_),   |
|                     |           |            |    and hyphens (-).   |
+---------------------+-----------+------------+-----------------------+
| description         | No        | String     | -  Provides           |
|                     |           |            |    supplementary      |
|                     |           |            |    information about  |
|                     |           |            |    the load balancer. |
|                     |           |            |                       |
|                     |           |            | -  The value contains |
|                     |           |            |    0 to 128           |
|                     |           |            |    characters and     |
|                     |           |            |    cannot contain     |
|                     |           |            |    angle brackets (<  |
|                     |           |            |    and >).            |
+---------------------+-----------+------------+-----------------------+
| bandwidth           | No        | Integer    | -  Specifies the      |
|                     |           |            |    bandwidth          |
|                     |           |            |    (Mbit/s). This     |
|                     |           |            |    parameter is       |
|                     |           |            |    mandatory when     |
|                     |           |            |    **type** is set to |
|                     |           |            |    **External**.      |
|                     |           |            |                       |
|                     |           |            | -  The value ranges   |
|                     |           |            |    from 1 to 500.     |
|                     |           |            |                       |
|                     |           |            | (The specific range   |
|                     |           |            | may vary depending on |
|                     |           |            | the configuration in  |
|                     |           |            | each region. You can  |
|                     |           |            | see the bandwidth     |
|                     |           |            | range of each region  |
|                     |           |            | on the management     |
|                     |           |            | console.)             |
+---------------------+-----------+------------+-----------------------+
| admin_state_up      | No        | Integ      | -  Specifies the      |
|                     |           | er/Boolean |    administrative     |
|                     |           |            |    status of the load |
|                     |           |            |    balancer.          |
|                     |           |            |                       |
|                     |           |            | -  Optional values:   |
|                     |           |            |                       |
|                     |           |            | **0** or **false**:   |
|                     |           |            | indicates that the    |
|                     |           |            | load balancer is      |
|                     |           |            | stopped. Only users   |
|                     |           |            | are allowed to enter  |
|                     |           |            | the two values.       |
|                     |           |            |                       |
|                     |           |            | **1** or **true**:    |
|                     |           |            | indicates that the    |
|                     |           |            | load balancer is      |
|                     |           |            | running properly.     |
|                     |           |            |                       |
|                     |           |            | **2** or **false**:   |
|                     |           |            | indicates that the    |
|                     |           |            | load balancer is      |
|                     |           |            | frozen. Only the      |
|                     |           |            | administrator is      |
|                     |           |            | allowed to enter the  |
|                     |           |            | two values.           |
+---------------------+-----------+------------+-----------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "description": "simple lb",
| "name": "loadbalancer1",
| "bandwidth": 200,
| "admin_state_up": true
| }

#. Response

-  Response parameters

   1. Parameter description

+---------------------+----------------------+-------------------------+
| Parameter           | Type                 | Description             |
+=====================+======================+=========================+
| uri                 | String               | Specifies the URI       |
|                     |                      | returned by Combined    |
|                     |                      | API after the job for   |
|                     |                      | modifying a load        |
|                     |                      | balancer is delivered.  |
+---------------------+----------------------+-------------------------+
| job_id              | String               | Specifies the unique ID |
|                     |                      | assigned to the job for |
|                     |                      | modifying a load        |
|                     |                      | balancer in Combined    |
|                     |                      | API.                    |
+---------------------+----------------------+-------------------------+

-  Example response

| {
| "uri":
  "/v1/73cd9140bec7427ab9952b4ed75924e0/jobs/4010b39d4fbb4645014fcfddf4b32d15",
| "job_id": "4010b39d4fbb4645014fcfddf4b32d15"
| }

#. Status Code

-  Normal

200

-  Error

+--------+---------------------------+--------------------------------+
| Status | Message                   | Description                    |
| Code   |                           |                                |
+========+===========================+================================+
| 400    | badRequest                | Request error.                 |
+--------+---------------------------+--------------------------------+
| 401    | unauthorized              | Authentication failed.         |
+--------+---------------------------+--------------------------------+
| 403    | userDisabled              | You do not have the permission |
|        |                           | to perform the operation.      |
+--------+---------------------------+--------------------------------+
| 404    | Not Found                 | The requested page does not    |
|        |                           | exist.                         |
+--------+---------------------------+--------------------------------+
| 500    | authFault                 | System error.                  |
+--------+---------------------------+--------------------------------+
| 503    | serviceUnavailable        | The service is unavailable.    |
+--------+---------------------------+--------------------------------+

Querying Details of a Load Balancer
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query details about a load balancer.

2. URI

GET /v1.0/{project_id}/elbaas/loadbalancers/{loadbalancer_id}

1. Parameter description

+-----------+---------+---------+-------------------------------------+
| Parameter | Ma      | Type    | Description                         |
|           | ndatory |         |                                     |
+===========+=========+=========+=====================================+
| p         | Yes     | String  | Specifies the project ID.           |
| roject_id |         |         |                                     |
+-----------+---------+---------+-------------------------------------+
| loadba    | Yes     | String  | Specifies the load balancer ID.     |
| lancer_id |         |         |                                     |
+-----------+---------+---------+-------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+------------+-----------+--------------------------------------------+
| Parameter  | Type      | Description                                |
+============+===========+============================================+
| v          | String    | Specifies the private IP address of the    |
| ip_address |           | load balancer.                             |
+------------+-----------+--------------------------------------------+
| u          | String    | Specifies the time when the load balancer  |
| pdate_time |           | was updated.                               |
+------------+-----------+--------------------------------------------+
| c          | String    | Specifies the time when the load balancer  |
| reate_time |           | was created.                               |
+------------+-----------+--------------------------------------------+
| id         | String    | Specifies the load balancer ID.            |
+------------+-----------+--------------------------------------------+
| status     | String    | -  Specifies the load balancer status.     |
|            |           |                                            |
|            |           | -  The value can be **ACTIVE**,            |
|            |           |    **PENDING_CREATE**, or **ERROR**.       |
+------------+-----------+--------------------------------------------+
| bandwidth  | Integer   | Specifies the bandwidth (Mbit/s).          |
+------------+-----------+--------------------------------------------+
| vpc_id     | String    | Specifies the VPC ID.                      |
+------------+-----------+--------------------------------------------+
| admi       | Integer   | -  Specifies the administrative status of  |
| n_state_up |           |    the load balancer.                      |
|            |           |                                            |
|            |           | -  The following options are available:    |
|            |           |                                            |
|            |           | **0**: The load balancer is disabled.      |
|            |           |                                            |
|            |           | **1**: The load balancer is running        |
|            |           | properly.                                  |
|            |           |                                            |
|            |           | **2**: The load balancer is frozen.        |
+------------+-----------+--------------------------------------------+
| vip        | String    | This parameter is unavailable now.         |
| _subnet_id |           |                                            |
+------------+-----------+--------------------------------------------+
| type       | String    | Specifies the network type of the load     |
|            |           | balancer. The value is **External**.       |
+------------+-----------+--------------------------------------------+
| name       | String    | Specifies the load balancer name.          |
+------------+-----------+--------------------------------------------+
| d          | String    | Provides supplementary information about   |
| escription |           | the load balancer.                         |
+------------+-----------+--------------------------------------------+
| securit    | String    | -  Specifies the security group ID.        |
| y_group_id |           |                                            |
|            |           | -  **null** is displayed for this          |
|            |           |    parameter when **type** is set to       |
|            |           |    **External**.                           |
+------------+-----------+--------------------------------------------+

-  Example response

| {
| "vip_address": "192.144.62.114",
| "update_time": "2015-09-14 02:34:32",
| "create_time": "2015-09-14 02:34:32",
| "id": "0b07acf06d243925bc24a0ac7445267a",
| "status": "ACTIVE",
| "bandwidth": 1,
| "security_group_id": null,
| "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
| "admin_state_up": 1,
| "vip_subnet_id": null,
| "type": "External",
| "name": "MY_ELB",
| "description": null
| }

#. Status Code

-  Normal

200

-  Error

+--------+----------------------------+--------------------------------+
| Status | Message                    | Description                    |
| Code   |                            |                                |
+========+============================+================================+
| 400    | badRequest                 | Request error.                 |
+--------+----------------------------+--------------------------------+
| 401    | unauthorized               | Authentication failed.         |
+--------+----------------------------+--------------------------------+
| 403    | userDisabled               | You do not have the permission |
|        |                            | to perform the operation.      |
+--------+----------------------------+--------------------------------+
| 404    | Not Found                  | The requested page does not    |
|        |                            | exist.                         |
+--------+----------------------------+--------------------------------+
| 500    | authFault                  | System error.                  |
+--------+----------------------------+--------------------------------+
| 503    | serviceUnavailable         | The service is unavailable.    |
+--------+----------------------------+--------------------------------+

Querying Load Balancers
~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query load balancers and display them in a list.

2. URI

GET /v1.0/{project_id}/elbaas/loadbalancers

1. Parameter description

+---------------------+------------+------------+---------------------+
| Parameter           | Mandatory  | Type       | Description         |
+=====================+============+============+=====================+
| project_id          | Yes        | String     | Specifies the       |
|                     |            |            | project ID.         |
+---------------------+------------+------------+---------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------------------+---------------+--------------------------------+
| Parameter           | Type          | Description                    |
+=====================+===============+================================+
| loadbalancers       | Array         | Lists the load balancers.      |
+---------------------+---------------+--------------------------------+
| instance_num        | String        | Specifies the number of load   |
|                     |               | balancers.                     |
+---------------------+---------------+--------------------------------+

2. **loadbalancers** parameter description

+--------------------+---------------+--------------------------------+
| Parameter          | Type          | Description                    |
+====================+===============+================================+
| vip_address        | String        | Specifies the private IP       |
|                    |               | address of the load balancer.  |
+--------------------+---------------+--------------------------------+
| update_time        | String        | Specifies the time when the    |
|                    |               | listener was updated.          |
+--------------------+---------------+--------------------------------+
| create_time        | String        | Specifies the time when the    |
|                    |               | listener was created.          |
+--------------------+---------------+--------------------------------+
| id                 | String        | Specifies the load balancer    |
|                    |               | ID.                            |
+--------------------+---------------+--------------------------------+
| status             | String        | -  Specifies the load balancer |
|                    |               |    status.                     |
|                    |               |                                |
|                    |               | -  The value can be            |
|                    |               |    **ACTIVE**,                 |
|                    |               |    **PENDING_CREATE**, or      |
|                    |               |    **ERROR**.                  |
+--------------------+---------------+--------------------------------+
| bandwidth          | Integer       | Specifies the bandwidth.       |
+--------------------+---------------+--------------------------------+
| vpc_id             | String        | Specifies the VPC ID.          |
+--------------------+---------------+--------------------------------+
| admin_state_up     | Integer       | -  Specifies the               |
|                    |               |    administrative status of    |
|                    |               |    the load balancer.          |
|                    |               |                                |
|                    |               | -  The value options are as    |
|                    |               |    follows:                    |
|                    |               |                                |
|                    |               | **0**: The load balancer is    |
|                    |               | disabled.                      |
|                    |               |                                |
|                    |               | **1**: The load balancer is    |
|                    |               | running properly.              |
|                    |               |                                |
|                    |               | **2**: The load balancer is    |
|                    |               | frozen.                        |
+--------------------+---------------+--------------------------------+
| vip_subnet_id      | String        | This parameter is unavailable  |
|                    |               | now.                           |
+--------------------+---------------+--------------------------------+
| type               | String        | Specifies the network type of  |
|                    |               | the load balancer. The value   |
|                    |               | is **External**.               |
+--------------------+---------------+--------------------------------+
| name               | String        | Specifies the load balancer    |
|                    |               | name.                          |
+--------------------+---------------+--------------------------------+
| description        | String        | Description                    |
+--------------------+---------------+--------------------------------+
| security_group_id  | String        | -  Specifies the security      |
|                    |               |    group ID.                   |
|                    |               |                                |
|                    |               | -  **null** is displayed for   |
|                    |               |    this parameter when         |
|                    |               |    **type** is set to          |
|                    |               |    **External**.               |
+--------------------+---------------+--------------------------------+

-  Example response

| {
| "loadbalancers": [
| {
| "vip_address": "192.144.62.114",
| "update_time": "2015-09-14 02:34:32",
| "create_time": "2015-09-14 02:34:32",
| "id": "0b07acf06d243925bc24a0ac7445267a",
| "status": "ACTIVE",
| "bandwidth": 1,
| "security_group_id": null,
| "vpc_id": "f54a3ffd-7a55-4568-9e3d-f0ff2d46a107",
| "admin_state_up": 1,
| "vip_subnet_id": null,
| "type": "External",
| "name": "MY_ELB",
| "description": null
| }
| ],
| "instance_num": "1"
| }

#. Status Codes

-  Normal

200

-  Abnormal

+-------+-----------------------------+--------------------------------+
| S     | Message                     | Description                    |
| tatus |                             |                                |
| Code  |                             |                                |
+=======+=============================+================================+
| 400   | badRequest                  | Request error.                 |
+-------+-----------------------------+--------------------------------+
| 401   | unauthorized                | Authentication failed.         |
+-------+-----------------------------+--------------------------------+
| 403   | userDisabled                | You do not have the permission |
|       |                             | to perform the operation.      |
+-------+-----------------------------+--------------------------------+
| 404   | Not Found                   | The requested page does not    |
|       |                             | exist.                         |
+-------+-----------------------------+--------------------------------+
| 500   | authFault                   | Internal error.                |
+-------+-----------------------------+--------------------------------+
| 503   | serviceUnavailable          | Service unavailable.           |
+-------+-----------------------------+--------------------------------+

Listener
--------

1. .. rubric:: Adding a Listener
      :name: adding-a-listener

   #. Function

This API is used to add a listener to a load balancer.

2. URI

POST /v1.0/{project_id}/elbaas/listeners

1. Parameter description

+----------------------+-----------+---------+---------------------------+
| Parameter            | Mandatory | Type    | Description               |
+======================+===========+=========+===========================+
| project_id           | Yes       | String  | Specifies the project ID. |
+----------------------+-----------+---------+---------------------------+
| name                 | Yes       | String  | -  Specifies the listener |
|                      |           |         |    name.                  |
|                      |           |         |                           |
|                      |           |         | -  The value can contain  |
|                      |           |         |    1 to 64 characters     |
|                      |           |         |    that consist of        |
|                      |           |         |    letters, digits,       |
|                      |           |         |    underscores (_), and   |
|                      |           |         |    hyphens (-).           |
+----------------------+-----------+---------+---------------------------+
| description          | No        | String  | -  Provides supplementary |
|                      |           |         |    information about the  |
|                      |           |         |    listener.              |
|                      |           |         |                           |
|                      |           |         | -  The value contains 0   |
|                      |           |         |    to 128 characters and  |
|                      |           |         |    cannot contain angle   |
|                      |           |         |    brackets (< and >).    |
+----------------------+-----------+---------+---------------------------+
| loadbalancer_id      | Yes       | String  | Specifies the load        |
|                      |           |         | balancer ID.              |
+----------------------+-----------+---------+---------------------------+
| protocol             | Yes       | String  | -  Specifies the protocol |
|                      |           |         |    used by the listener.  |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **HTTP**, **TCP**,     |
|                      |           |         |    **HTTPS**, **SSL**, or |
|                      |           |         |    **UDP**.               |
|                      |           |         |                           |
|                      |           |         | -  A UDP listener cannot  |
|                      |           |         |    be added to a private  |
|                      |           |         |    network load balancer. |
+----------------------+-----------+---------+---------------------------+
| port                 | Yes       | Integer | -  Specifies the port     |
|                      |           |         |    used by the listener.  |
|                      |           |         |                           |
|                      |           |         | -  The port number ranges |
|                      |           |         |    from 1 to 65535.       |
+----------------------+-----------+---------+---------------------------+
| backend_protocol     | Yes       | String  | -  Specifies the backend  |
|                      |           |         |    ECS protocol.          |
|                      |           |         |                           |
|                      |           |         | If **protocol** is set to |
|                      |           |         | **UDP**, the value of     |
|                      |           |         | this parameter can only   |
|                      |           |         | be **UDP**.               |
|                      |           |         |                           |
|                      |           |         | If **protocol** is set to |
|                      |           |         | **SSL**, the value of     |
|                      |           |         | this parameter can only   |
|                      |           |         | be **TCP**.               |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **HTTP**, **TCP**, or  |
|                      |           |         |    **UDP**.               |
+----------------------+-----------+---------+---------------------------+
| backend_port         | Yes       | Integer | -  Specifies the port     |
|                      |           |         |    used by backend ECSs.  |
|                      |           |         |                           |
|                      |           |         | -  The port number ranges |
|                      |           |         |    from 1 to 65535.       |
+----------------------+-----------+---------+---------------------------+
| lb_algorithm         | Yes       | String  | -  Specifies the load     |
|                      |           |         |    balancing algorithm.   |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **roundrobin**,        |
|                      |           |         |    **leastconn**, or      |
|                      |           |         |    **source**.            |
+----------------------+-----------+---------+---------------------------+
| session_sticky       | No        | Boolean | -  Specifies whether to   |
|                      |           |         |    enable the sticky      |
|                      |           |         |    session feature.       |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **true** or **false**. |
|                      |           |         |    The feature is enabled |
|                      |           |         |    when the value is      |
|                      |           |         |    **true**.              |
|                      |           |         |                           |
|                      |           |         | -  If **protocol** is set |
|                      |           |         |    to **SSL**, the sticky |
|                      |           |         |    session feature is not |
|                      |           |         |    supported and the      |
|                      |           |         |    parameter is invalid.  |
|                      |           |         |                           |
|                      |           |         | -  If **protocol** is set |
|                      |           |         |    to **HTTP**,           |
|                      |           |         |    **HTTPS**, or **TCP**  |
|                      |           |         |    and **lb_algorithm**   |
|                      |           |         |    is not **roundrobin**, |
|                      |           |         |    the value of this      |
|                      |           |         |    parameter can only be  |
|                      |           |         |    **false**.             |
+----------------------+-----------+---------+---------------------------+
| sti                  | No        | String  | Specifies where the       |
| cky_session_type     |           |         | cookie is from. The only  |
|                      |           |         | value is **insert**,      |
|                      |           |         | indicating that the       |
|                      |           |         | cookie is inserted by the |
|                      |           |         | load balancer.            |
|                      |           |         |                           |
|                      |           |         | -  This parameter is      |
|                      |           |         |    valid when             |
|                      |           |         |    **protocol** is set to |
|                      |           |         |    **HTTP** and           |
|                      |           |         |    **session_sticky** to  |
|                      |           |         |    **true**.              |
|                      |           |         |                           |
|                      |           |         | -  This parameter is      |
|                      |           |         |    invalid when           |
|                      |           |         |    **protocol** is set to |
|                      |           |         |    **TCP**, **SSL**, or   |
|                      |           |         |    **UDP**, which means   |
|                      |           |         |    that the parameter is  |
|                      |           |         |    unavailable or its     |
|                      |           |         |    value is set to        |
|                      |           |         |    **null**.              |
+----------------------+-----------+---------+---------------------------+
| cookie_timeout       | No        | Integer | -  Specifies the cookie   |
|                      |           |         |    timeout duration. This |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **HTTP**,       |
|                      |           |         |    **session_sticky** to  |
|                      |           |         |    **true**, and          |
|                      |           |         |                           |
|                      |           |         |   **sticky_session_type** |
|                      |           |         |    to **insert**. This    |
|                      |           |         |    parameter is invalid   |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **TCP**,        |
|                      |           |         |    **SSL**, or **UDP**.   |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **1** to **1440**.     |
+----------------------+-----------+---------+---------------------------+
| tcp_timeout          | No        | Integer | -  Specifies the TCP      |
|                      |           |         |    session timeout        |
|                      |           |         |    duration. This         |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **TCP**.        |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **1** to **1440**.     |
+----------------------+-----------+---------+---------------------------+
| tcp_draining         | No        | Boolean | -  Specifies whether to   |
|                      |           |         |    maintain TCP           |
|                      |           |         |    connections to a       |
|                      |           |         |    backend ECS that has   |
|                      |           |         |    been removed. This     |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **TCP**.        |
|                      |           |         |                           |
|                      |           |         | -  The value can be       |
|                      |           |         |    **true** or **false**. |
+----------------------+-----------+---------+---------------------------+
| tcp_draining_timeout | No        | Integer | -  Specifies the timeout  |
|                      |           |         |    duration for           |
|                      |           |         |    maintaining TCP        |
|                      |           |         |    connections to a       |
|                      |           |         |    backend ECS that has   |
|                      |           |         |    been removed in the    |
|                      |           |         |    unit of minute.        |
|                      |           |         |                           |
|                      |           |         | This parameter is valid   |
|                      |           |         | when **protocol** is set  |
|                      |           |         | to **TCP** and            |
|                      |           |         | **tcp_draining** to       |
|                      |           |         | **true**.                 |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **0** to **60**.       |
+----------------------+-----------+---------+---------------------------+
| certificate_id       | No        | String  | -  Specifies the          |
|                      |           |         |    certificate ID. This   |
|                      |           |         |    parameter is mandatory |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **HTTPS** or    |
|                      |           |         |    **SSL**.               |
|                      |           |         |                           |
|                      |           |         | -  The ID can be obtained |
|                      |           |         |    from the certificate   |
|                      |           |         |    list.                  |
+----------------------+-----------+---------+---------------------------+
| certificates         | No        | String  | -  Lists the certificate  |
|                      |           |         |    IDs if **protocol** is |
|                      |           |         |    set to **HTTPS**.      |
|                      |           |         |                           |
|                      |           |         | -  This parameter is      |
|                      |           |         |    mandatory in the SNI   |
|                      |           |         |    scenario and is valid  |
|                      |           |         |    only when the load     |
|                      |           |         |    balancer is a public   |
|                      |           |         |    network load balancer. |
+----------------------+-----------+---------+---------------------------+
| udp_timeout          | No        | Integer | -  Specifies the UDP      |
|                      |           |         |    session timeout        |
|                      |           |         |    duration. This         |
|                      |           |         |    parameter is valid     |
|                      |           |         |    when **protocol** is   |
|                      |           |         |    set to **UDP**.        |
|                      |           |         |                           |
|                      |           |         | -  The value ranges from  |
|                      |           |         |    **1** to **1440**.     |
+----------------------+-----------+---------+---------------------------+
| ssl_protocols        | No        | String  | -  Specifies the          |
|                      |           |         |    supported SSL/TLS      |
|                      |           |         |    protocol version. This |
|                      |           |         |    parameter is available |
|                      |           |         |    only when **protocol** |
|                      |           |         |    is set to **HTTPS** or |
|                      |           |         |    **SSL**.               |
|                      |           |         |                           |
|                      |           |         | -  The value is           |
|                      |           |         |    **TLSv1.2** or         |
|                      |           |         |    **TLSv1.2 TLSv1.1      |
|                      |           |         |    TLSv1** and the        |
|                      |           |         |    default value is       |
|                      |           |         |    **TLSv1.2**.           |
+----------------------+-----------+---------+---------------------------+
| ssl_ciphers          | No        | String  | -  Specifies the cipher   |
|                      |           |         |    suites supported by a  |
|                      |           |         |    specific SSL/TLS       |
|                      |           |         |    protocol version. This |
|                      |           |         |    parameter is available |
|                      |           |         |    only when **protocol** |
|                      |           |         |    is set to **HTTPS** or |
|                      |           |         |    **SSL**.               |
|                      |           |         |                           |
|                      |           |         | -  The value is           |
|                      |           |         |    **Default**,           |
|                      |           |         |    **Extended**, or       |
|                      |           |         |    **Strict**.            |
|                      |           |         |                           |
|                      |           |         | The value of **Default**  |
|                      |           |         | is                        |
|                      |           |         | **ECDHE-                  |
|                      |           |         | RSA-AES256-GCM-SHA384:ECD |
|                      |           |         | HE-RSA-AES128-GCM-SHA256: |
|                      |           |         | ECDHE-RSA-AES256-SHA384:E |
|                      |           |         | CDHE-RSA-AES128-SHA256**. |
|                      |           |         |                           |
|                      |           |         | The value of **Extended** |
|                      |           |         | is                        |
|                      |           |         | **                        |
|                      |           |         | ECDHE-ECDSA-AES128-SHA256 |
|                      |           |         | :ECDHE-RSA-AES128-SHA256: |
|                      |           |         | AES128-SHA256:AES256-SHA2 |
|                      |           |         | 56:ECDHE-ECDSA-AES256-SHA |
|                      |           |         | 384:ECDHE-RSA-AES256-SHA3 |
|                      |           |         | 84:ECDHE-ECDSA-AES128-SHA |
|                      |           |         | :ECDHE-RSA-AES128-SHA:DHE |
|                      |           |         | -RSA-AES128-SHA:ECDHE-RSA |
|                      |           |         | -AES256-SHA:ECDHE-ECDSA-A |
|                      |           |         | ES256-SHA:AES128-SHA:AES2 |
|                      |           |         | 56-SHA:DHE-DSS-AES128-SHA |
|                      |           |         | :CAMELLIA128-SHA:EDH-RSA- |
|                      |           |         | DES-CBC3-SHA:DES-CBC3-SHA |
|                      |           |         | :ECDHE-RSA-RC4-SHA:RC4-SH |
|                      |           |         | A:DHE-RSA-AES256-SHA:DHE- |
|                      |           |         | DSS-AES256-SHA:DHE-RSA-CA |
|                      |           |         | MELLIA256-SHA:DHE-DSS-CAM |
|                      |           |         | ELLIA256-SHA:CAMELLIA256- |
|                      |           |         | SHA:EDH-DSS-DES-CBC3-SHA: |
|                      |           |         | DHE-RSA-CAMELLIA128-SHA:D |
|                      |           |         | HE-DSS-CAMELLIA128-SHA**. |
|                      |           |         |                           |
|                      |           |         | The value of **Strict**   |
|                      |           |         | is                        |
|                      |           |         | **ECDHE-RS                |
|                      |           |         | A-AES256-GCM-SHA384:ECDHE |
|                      |           |         | -RSA-AES128-GCM-SHA256**. |
|                      |           |         |                           |
|                      |           |         | The default value is      |
|                      |           |         | **Default**. The value    |
|                      |           |         | can only be set to        |
|                      |           |         | **Extended** if           |
|                      |           |         | **ssl_protocols** is set  |
|                      |           |         | to **TLSv1.2 TLSv1.1      |
|                      |           |         | TLSv1**.                  |
+----------------------+-----------+---------+---------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "name": "listener1",
| "description": "",
| "loadbalancer_id": "0b07acf06d243925bc24a0ac7445267a",
| "protocol": "HTTP",
| "port": 88,
| "backend_protocol": "HTTP",
| "backend_port": 80,
| "lb_algorithm": "roundrobin",
| "session_sticky": true,
| "sticky_session_type": "insert",
| "cookie_timeout": 100,
| "tcp_draining": true,
| "tcp_draining_timeout": 5
| }

#. Response

-  Response parameters

   1. Parameter description

+--------------------+----------------+-------------------------------+
| Parameter          | Type           | Description                   |
+====================+================+===============================+
| update_time        | String         | Specifies the time when the   |
|                    |                | listener was updated.         |
+--------------------+----------------+-------------------------------+
| backend_port       | Integer        | Specifies the port used by    |
|                    |                | backend ECSs.                 |
+--------------------+----------------+-------------------------------+
| id                 | String         | Specifies the listener ID.    |
+--------------------+----------------+-------------------------------+
| backend_protocol   | String         | Specifies the protocol used   |
|                    |                | by backend ECSs.              |
+--------------------+----------------+-------------------------------+
| s                  | String         | Specifies where the cookie is |
| ticky_session_type |                | from. The only value is       |
|                    |                | **insert**, indicating that   |
|                    |                | the cookie is inserted by the |
|                    |                | load balancer. This parameter |
|                    |                | is valid when **protocol** is |
|                    |                | set to **HTTP** and           |
|                    |                | **session_sticky** to         |
|                    |                | **true**.                     |
+--------------------+----------------+-------------------------------+
| description        | String         | Provides supplementary        |
|                    |                | information about the         |
|                    |                | listener.                     |
+--------------------+----------------+-------------------------------+
| loadbalancer_id    | String         | Specifies the load balancer   |
|                    |                | ID.                           |
+--------------------+----------------+-------------------------------+
| create_time        | String         | Specifies the time when the   |
|                    |                | listener was created.         |
+--------------------+----------------+-------------------------------+
| status             | String         | Specifies the listener        |
|                    |                | status. The value can be      |
|                    |                | **ACTIVE**,                   |
|                    |                | **PENDING_CREATE**, or        |
|                    |                | **ERROR**.                    |
+--------------------+----------------+-------------------------------+
| protocol           | String         | Specifies the protocol used   |
|                    |                | for load balancing at Layer 4 |
|                    |                | or Layer 7.                   |
+--------------------+----------------+-------------------------------+
| port               | Integer        | Specifies the port used by    |
|                    |                | the listener.                 |
+--------------------+----------------+-------------------------------+
| cookie_timeout     | Integer        | -  Specifies the cookie       |
|                    |                |    timeout duration in the    |
|                    |                |    unit of minute. This       |
|                    |                |    parameter is valid when    |
|                    |                |    **session_sticky** is set  |
|                    |                |    to **true** and            |
|                    |                |    **sticky_session_type** to |
|                    |                |    **insert**.                |
|                    |                |                               |
|                    |                | -  The value ranges from      |
|                    |                |    **1** to **1440**.         |
+--------------------+----------------+-------------------------------+
| admin_state_up     | Boolean        | -  Specifies the              |
|                    |                |    administrative status of   |
|                    |                |    the load balancer.         |
|                    |                |                               |
|                    |                | -  Two options are available: |
|                    |                |                               |
|                    |                | **false**: The load balancer  |
|                    |                | is disabled.                  |
|                    |                |                               |
|                    |                | **true**: The load balancer   |
|                    |                | is running properly.          |
+--------------------+----------------+-------------------------------+
| session_sticky     | Boolean        | Specifies whether to enable   |
|                    |                | the sticky session feature.   |
|                    |                | The feature is enabled when   |
|                    |                | the value is **true**.        |
+--------------------+----------------+-------------------------------+
| lb_algorithm       | String         | Specifies the load balancing  |
|                    |                | algorithm.                    |
+--------------------+----------------+-------------------------------+
| name               | String         | Specifies the listener name.  |
+--------------------+----------------+-------------------------------+
| tcp_draining       | Boolean        | -  Specifies whether to       |
|                    |                |    maintain TCP connections   |
|                    |                |    to a backend ECS that has  |
|                    |                |    been removed. This         |
|                    |                |    parameter is valid when    |
|                    |                |    **protocol** is set to     |
|                    |                |    **TCP**.                   |
|                    |                |                               |
|                    |                | -  The value can be **true**  |
|                    |                |    or **false**.              |
+--------------------+----------------+-------------------------------+
| tc                 | Integer        | -  Specifies the timeout      |
| p_draining_timeout |                |    duration for maintaining   |
|                    |                |    TCP connections to a       |
|                    |                |    backend ECS that has been  |
|                    |                |    removed in the unit of     |
|                    |                |    minute.                    |
|                    |                |                               |
|                    |                | This parameter is valid when  |
|                    |                | **protocol** is set to        |
|                    |                | **TCP** and **tcp_draining**  |
|                    |                | to **true**.                  |
|                    |                |                               |
|                    |                | -  The value ranges from      |
|                    |                |    **0** to **60**.           |
+--------------------+----------------+-------------------------------+
| ssl_protocols      | String         | -  Specifies the supported    |
|                    |                |    SSL/TLS protocol version.  |
|                    |                |                               |
|                    |                | -  This parameter is          |
|                    |                |    available only when        |
|                    |                |    **protocol** is set to     |
|                    |                |    **HTTPS** or **SSL**.      |
+--------------------+----------------+-------------------------------+
| ssl_ciphers        | String         | -  Specifies the cipher suite |
|                    |                |    of an encryption protocol. |
|                    |                |                               |
|                    |                | -  This parameter is          |
|                    |                |    available only when        |
|                    |                |    **protocol** is set to     |
|                    |                |    **HTTPS** or **SSL**.      |
+--------------------+----------------+-------------------------------+
| certificate_id     | String         | -  Specifies the default      |
|                    |                |    certificate ID.            |
|                    |                |                               |
|                    |                | -  This parameter is          |
|                    |                |    available only when        |
|                    |                |    **protocol** is set to     |
|                    |                |    **HTTPS** or **SSL**.      |
+--------------------+----------------+-------------------------------+
| certificates       | String         | -  Lists the certificate IDs  |
|                    |                |    if **protocol** is set to  |
|                    |                |    **HTTPS**.                 |
|                    |                |                               |
|                    |                | -  This parameter is          |
|                    |                |    mandatory in the SNI       |
|                    |                |    scenario.                  |
+--------------------+----------------+-------------------------------+

-  Example response

| {
| "update_time": "2015-09-15 07:41:17",
| "backend_port": 80,
| "tcp_draining": true,
| "id": "248425d7b97dc26920eb23720115e068",
| "backend_protocol": "HTTP",
| "sticky_session_type": "insert",
| "description": "",
| "loadbalancer_id": "0b07acf06d243925bc24a0ac7445267a",
| "create_time": "2015-09-15 07:41:17",
| "status": "ACTIVE",
| "protocol": "TCP",
| "port": 88,
| "cookie_timeout": 100,
| "admin_state_up": true,
| "session_sticky": true,
| "lb_algorithm": "roundrobin",
| "name": "listener1",
| "tcp_draining": true,
| "tcp_draining_timeout": 5
| }

#. Status Code

-  Normal

200

-  Error

+-------+----------------------------+--------------------------------+
| S     | Message                    | Description                    |
| tatus |                            |                                |
| Code  |                            |                                |
+=======+============================+================================+
| 400   | badRequest                 | Request error.                 |
+-------+----------------------------+--------------------------------+
| 401   | unauthorized               | Authentication failed.         |
+-------+----------------------------+--------------------------------+
| 403   | userDisabled               | You do not have the permission |
|       |                            | to perform the operation.      |
+-------+----------------------------+--------------------------------+
| 404   | Not Found                  | The requested page does not    |
|       |                            | exist.                         |
+-------+----------------------------+--------------------------------+
| 500   | authFault                  | System error.                  |
+-------+----------------------------+--------------------------------+
| 503   | serviceUnavailable         | The service is unavailable.    |
+-------+----------------------------+--------------------------------+

Deleting a Listener
~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to delete a listener.

2. URI

DELETE /v1.0/{project_id}/elbaas/listeners/{listener_id}

1. Parameter description

+---------+----------+---------+--------------------------------------+
| Pa      | M        | Type    | Description                          |
| rameter | andatory |         |                                      |
+=========+==========+=========+======================================+
| pro     | Yes      | String  | Specifies the project ID.            |
| ject_id |          |         |                                      |
+---------+----------+---------+--------------------------------------+
| list    | Yes      | String  | Specifies the listener ID.           |
| ener_id |          |         |                                      |
+---------+----------+---------+--------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

None

-  Example response

None

#. Status Code

-  Normal

204

-  Error

+-------+----------------------------+--------------------------------+
| S     | Message                    | Description                    |
| tatus |                            |                                |
| Code  |                            |                                |
+=======+============================+================================+
| 400   | badRequest                 | Request error.                 |
+-------+----------------------------+--------------------------------+
| 401   | unauthorized               | Authentication failed.         |
+-------+----------------------------+--------------------------------+
| 403   | userDisabled               | You do not have the permission |
|       |                            | to perform the operation.      |
+-------+----------------------------+--------------------------------+
| 404   | Not Found                  | The requested page does not    |
|       |                            | exist.                         |
+-------+----------------------------+--------------------------------+
| 500   | authFault                  | System error.                  |
+-------+----------------------------+--------------------------------+
| 503   | serviceUnavailable         | The service is unavailable.    |
+-------+----------------------------+--------------------------------+

Modifying a Listener
~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to modify the listener information, including the
listener name, description, and status.

2. URI

PUT /v1.0/{project_id}/elbaas/listeners/{listener_id}

1. Parameter description

+--------+--------+-------+-------------------------------------------+
| Par    | Man    | Type  | Description                               |
| ameter | datory |       |                                           |
+========+========+=======+===========================================+
| proj   | Yes    | S     | Specifies the project ID.                 |
| ect_id |        | tring |                                           |
+--------+--------+-------+-------------------------------------------+
| liste  | Yes    | S     | Specifies the listener ID.                |
| ner_id |        | tring |                                           |
+--------+--------+-------+-------------------------------------------+
| name   | No     | S     | -  Specifies the listener name.           |
|        |        | tring |                                           |
|        |        |       | -  The value can contain 1 to 64          |
|        |        |       |    characters that consist of letters,    |
|        |        |       |    digits, underscores (_), and hyphens   |
|        |        |       |    (-).                                   |
+--------+--------+-------+-------------------------------------------+
| descr  | No     | S     | -  Provides supplementary information     |
| iption |        | tring |    about the listener.                    |
|        |        |       |                                           |
|        |        |       | -  The value contains 0 to 128 characters |
|        |        |       |    and cannot contain angle brackets (<   |
|        |        |       |    and >).                                |
+--------+--------+-------+-------------------------------------------+
| port   | No     | In    | -  Specifies the port used by the         |
|        |        | teger |    listener.                              |
|        |        |       |                                           |
|        |        |       | -  The port number ranges from 1 to       |
|        |        |       |    65535.                                 |
+--------+--------+-------+-------------------------------------------+
| backen | No     | In    | -  Specifies the port used by backend     |
| d_port |        | teger |    ECSs.                                  |
|        |        |       |                                           |
|        |        |       | -  The port number ranges from 1 to       |
|        |        |       |    65535.                                 |
+--------+--------+-------+-------------------------------------------+
| lb_alg | No     | S     | -  Specifies the load balancing           |
| orithm |        | tring |    algorithm.                             |
|        |        |       |                                           |
|        |        |       | -  The value can be **roundrobin**,       |
|        |        |       |    **leastconn**, or **source**.          |
+--------+--------+-------+-------------------------------------------+
| tcp_t  | No     | In    | -  Specifies the TCP session timeout      |
| imeout |        | teger |    duration. This parameter is valid when |
|        |        |       |    **protocol** is set to **TCP**.        |
|        |        |       |                                           |
|        |        |       | -  The value ranges from **1** to         |
|        |        |       |    **1440**.                              |
+--------+--------+-------+-------------------------------------------+
| tcp_dr | No     | Bo    | -  Specifies whether to maintain TCP      |
| aining |        | olean |    connections to a backend ECS that has  |
|        |        |       |    been removed. This parameter is valid  |
|        |        |       |    when **protocol** is set to **TCP**.   |
|        |        |       |                                           |
|        |        |       | -  The value can be **true** or           |
|        |        |       |    **false**.                             |
+--------+--------+-------+-------------------------------------------+
| tc     | No     | In    | -  Specifies the timeout duration for     |
| p_drai |        | teger |    maintaining TCP connections to a       |
| ning_t |        |       |    backend ECS that has been removed in   |
| imeout |        |       |    the unit of minute.                    |
|        |        |       |                                           |
|        |        |       | This parameter is valid when **protocol** |
|        |        |       | is set to **TCP** and **tcp_draining** to |
|        |        |       | **true**.                                 |
|        |        |       |                                           |
|        |        |       | -  The value ranges from **0** to **60**. |
+--------+--------+-------+-------------------------------------------+
| udp_t  | No     | In    | -  Specifies the UDP session timeout      |
| imeout |        | teger |    duration. This parameter is valid when |
|        |        |       |    **protocol** is set to **UDP**.        |
|        |        |       |                                           |
|        |        |       | -  The value ranges from **1** to         |
|        |        |       |    **1440**.                              |
+--------+--------+-------+-------------------------------------------+
| s      | No     | S     | -  Specifies the supported SSL/TLS        |
| sl_pro |        | tring |    protocol version. This parameter is    |
| tocols |        |       |    available only when **protocol** is    |
|        |        |       |    set to **HTTPS** or **SSL**.           |
|        |        |       |                                           |
|        |        |       | -  The value is **TLSv1.2** or **TLSv1.2  |
|        |        |       |    TLSv1.1 TLSv1** and the default value  |
|        |        |       |    is **TLSv1.2**.                        |
+--------+--------+-------+-------------------------------------------+
| ssl_c  | No     | S     | -  Specifies the cipher suites supported  |
| iphers |        | tring |    by a specific SSL/TLS protocol         |
|        |        |       |    version. This parameter is available   |
|        |        |       |    only when **protocol** is set to       |
|        |        |       |    **HTTPS** or **SSL**.                  |
|        |        |       |                                           |
|        |        |       | -  The value is **Default**,              |
|        |        |       |    **Extended**, or **Strict**.           |
|        |        |       |                                           |
|        |        |       | The value of **Default** is               |
|        |        |       | **ECDHE-RSA-AES256-GCM-SHA                |
|        |        |       | 384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA |
|        |        |       | -AES256-SHA384:ECDHE-RSA-AES128-SHA256**. |
|        |        |       |                                           |
|        |        |       | The value of **Extended** is              |
|        |        |       | **ECDHE-ECDSA-AES128-SHA256:ECDHE-R       |
|        |        |       | SA-AES128-SHA256:AES128-SHA256:AES256-SHA |
|        |        |       | 256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-A |
|        |        |       | ES256-SHA384:ECDHE-ECDSA-AES128-SHA:ECDHE |
|        |        |       | -RSA-AES128-SHA:DHE-RSA-AES128-SHA:ECDHE- |
|        |        |       | RSA-AES256-SHA:ECDHE-ECDSA-AES256-SHA:AES |
|        |        |       | 128-SHA:AES256-SHA:DHE-DSS-AES128-SHA:CAM |
|        |        |       | ELLIA128-SHA:EDH-RSA-DES-CBC3-SHA:DES-CBC |
|        |        |       | 3-SHA:ECDHE-RSA-RC4-SHA:RC4-SHA:DHE-RSA-A |
|        |        |       | ES256-SHA:DHE-DSS-AES256-SHA:DHE-RSA-CAME |
|        |        |       | LLIA256-SHA:DHE-DSS-CAMELLIA256-SHA:CAMEL |
|        |        |       | LIA256-SHA:EDH-DSS-DES-CBC3-SHA:DHE-RSA-C |
|        |        |       | AMELLIA128-SHA:DHE-DSS-CAMELLIA128-SHA**. |
|        |        |       |                                           |
|        |        |       | The value of **Strict** is                |
|        |        |       | **ECDHE-RSA-AES256-                       |
|        |        |       | GCM-SHA384:ECDHE-RSA-AES128-GCM-SHA256**. |
|        |        |       |                                           |
|        |        |       | The default value is **Default**. The     |
|        |        |       | value can only be set to **Extended** if  |
|        |        |       | **ssl_protocols** is set to **TLSv1.2     |
|        |        |       | TLSv1.1 TLSv1**.                          |
+--------+--------+-------+-------------------------------------------+
| ce     | No     | S     | -  Specifies the default certificate ID.  |
| rtific |        | tring |    This parameter is mandatory when       |
| ate_id |        |       |    **protocol** is set to **HTTPS** or    |
|        |        |       |    **SSL**.                               |
|        |        |       |                                           |
|        |        |       | -  The ID can be obtained from the        |
|        |        |       |    certificate list.                      |
+--------+--------+-------+-------------------------------------------+
| certif | No     | S     | -  Lists the certificate IDs if           |
| icates |        | tring |    **protocol** is set to **HTTPS**.      |
|        |        |       |                                           |
|        |        |       | -  This parameter is mandatory in the SNI |
|        |        |       |    scenario.                              |
|        |        |       |                                           |
|        |        |       | -  This parameter is valid only when the  |
|        |        |       |    load balancer is a public network load |
|        |        |       |    balancer.                              |
+--------+--------+-------+-------------------------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "name": "lis",
| "description": "",
| "port": 9090,
| "backend_port": 9090,
| "lb_algorithm": "roundrobin"
| }

#. Response

-  Response parameters

   1. Parameter description

+-------------+---------+---------------------------------------------+
| Parameter   | Type    | Description                                 |
+=============+=========+=============================================+
| update_time | String  | Specifies the time when the listener was    |
|             |         | updated.                                    |
+-------------+---------+---------------------------------------------+
| b           | Integer | Specifies the port used by backend ECSs.    |
| ackend_port |         |                                             |
+-------------+---------+---------------------------------------------+
| id          | String  | Specifies the listener ID in UUID format.   |
+-------------+---------+---------------------------------------------+
| backe       | String  | Specifies the protocol used by backend      |
| nd_protocol |         | ECSs.                                       |
+-------------+---------+---------------------------------------------+
| sticky_s    | String  | Specifies where the cookie is from. The     |
| ession_type |         | only value is **insert**, indicating that   |
|             |         | the cookie is inserted by the load          |
|             |         | balancer.                                   |
|             |         |                                             |
|             |         | -  This parameter is valid when             |
|             |         |    **protocol** is set to **HTTP** and      |
|             |         |    **session_sticky** to **true**.          |
|             |         |                                             |
|             |         | -  This parameter is invalid when           |
|             |         |    **protocol** is set to **TCP**, **SSL**, |
|             |         |    or **UDP**, which means that the         |
|             |         |    parameter is unavailable or its value is |
|             |         |    set to **null**.                         |
+-------------+---------+---------------------------------------------+
| description | String  | Provides supplementary information about    |
|             |         | the listener.                               |
+-------------+---------+---------------------------------------------+
| load        | String  | Specifies the load balancer ID.             |
| balancer_id |         |                                             |
+-------------+---------+---------------------------------------------+
| create_time | String  | Specifies the time when the listener was    |
|             |         | created.                                    |
+-------------+---------+---------------------------------------------+
| status      | String  | Specifies the listener status. The value    |
|             |         | can be **ACTIVE**, **PENDING_CREATE**, or   |
|             |         | **ERROR**.                                  |
+-------------+---------+---------------------------------------------+
| protocol    | String  | Specifies the protocol used for load        |
|             |         | balancing at Layer 4 or Layer 7.            |
+-------------+---------+---------------------------------------------+
| port        | Integer | Specifies the port used by the listener.    |
+-------------+---------+---------------------------------------------+
| coo         | Integer | -  Specifies the cookie timeout duration.   |
| kie_timeout |         |    This parameter is valid when             |
|             |         |    **session_sticky** is set to **true**    |
|             |         |    and **sticky_session_type** to           |
|             |         |    **insert**.                              |
|             |         |                                             |
|             |         | -  The value ranges from **1** to **1440**. |
+-------------+---------+---------------------------------------------+
| adm         | Boolean | -  Specifies the administrative status of   |
| in_state_up |         |    the load balancer.                       |
|             |         |                                             |
|             |         | -  Two options are available:               |
|             |         |                                             |
|             |         | **false**: The load balancer is disabled.   |
|             |         |                                             |
|             |         | **true**: The load balancer is running      |
|             |         | properly.                                   |
+-------------+---------+---------------------------------------------+
| hea         | String  | Specifies the health check ID.              |
| lthcheck_id |         |                                             |
+-------------+---------+---------------------------------------------+
| ses         | Boolean | Specifies whether to enable the sticky      |
| sion_sticky |         | session feature. The feature is enabled     |
|             |         | when the value is **true**. This parameter  |
|             |         | is valid only when **protocol** is set to   |
|             |         | **HTTP**.                                   |
+-------------+---------+---------------------------------------------+
| l           | String  | Specifies the load balancing algorithm.     |
| b_algorithm |         |                                             |
+-------------+---------+---------------------------------------------+
| name        | String  | Specifies the listener name.                |
+-------------+---------+---------------------------------------------+
| t           | Boolean | -  Specifies whether to maintain TCP        |
| cp_draining |         |    connections to a backend ECS that has    |
|             |         |    been removed. This parameter is valid    |
|             |         |    when **protocol** is set to **TCP**.     |
|             |         |                                             |
|             |         | -  The value can be **true** or **false**.  |
+-------------+---------+---------------------------------------------+
| tcp_drain   | Integer | -  Specifies the timeout duration for       |
| ing_timeout |         |    maintaining TCP connections to a backend |
|             |         |    ECS that has been removed. The unit is   |
|             |         |    minute.                                  |
|             |         |                                             |
|             |         | This parameter is valid when **protocol**   |
|             |         | is set to **TCP** and **tcp_draining** to   |
|             |         | **true**.                                   |
|             |         |                                             |
|             |         | -  The value ranges from **0** to **60**.   |
+-------------+---------+---------------------------------------------+
| cer         | String  | Specifies the ID of the SSL certificate for |
| tificate_id |         | security authentication.                    |
|             |         |                                             |
|             |         | This parameter is mandatory when            |
|             |         | **protocol** is set to **HTTPS** or         |
|             |         | **SSL**. Otherwise, the parameter value is  |
|             |         | **null**.                                   |
+-------------+---------+---------------------------------------------+
| c           | String  | Lists the certificate IDs if **protocol**   |
| ertificates |         | is set to **HTTPS**.                        |
|             |         |                                             |
|             |         | This parameter is mandatory in the SNI      |
|             |         | scenario.                                   |
+-------------+---------+---------------------------------------------+

-  Example response

| {
| "update_time": "2016-12-01 07:12:59",
| "backend_port": 9090,
| "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
| "backend_protocol": "TCP",
| "sticky_session_type": null,
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "create_time": "2016-12-01 07:12:43",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "TCP",
| "cookie_timeout": 100,
| "port": 9092,
| "tcp_draining": true,
| "tcp_timeout": 1,
| "lb_algorithm": "roundrobin",
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| }

#. Status Code

-  Normal

200

-  Error

+-------+----------------------------+--------------------------------+
| S     | Message                    | Description                    |
| tatus |                            |                                |
| Code  |                            |                                |
+=======+============================+================================+
| 400   | badRequest                 | Request error.                 |
+-------+----------------------------+--------------------------------+
| 401   | unauthorized               | Authentication failed.         |
+-------+----------------------------+--------------------------------+
| 403   | userDisabled               | You do not have the permission |
|       |                            | to perform the operation.      |
+-------+----------------------------+--------------------------------+
| 404   | Not Found                  | The requested page does not    |
|       |                            | exist.                         |
+-------+----------------------------+--------------------------------+
| 500   | authFault                  | System error.                  |
+-------+----------------------------+--------------------------------+
| 503   | serviceUnavailable         | The service is unavailable.    |
+-------+----------------------------+--------------------------------+

Querying Details of a Listener
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query details about a listener.

2. URI

GET /v1.0/{project_id}/elbaas/listeners/{listener_id}

1. Parameter description

+---------+----------+---------+--------------------------------------+
| Pa      | M        | Type    | Description                          |
| rameter | andatory |         |                                      |
+=========+==========+=========+======================================+
| pro     | Yes      | String  | Specifies the project ID.            |
| ject_id |          |         |                                      |
+---------+----------+---------+--------------------------------------+
| list    | Yes      | String  | Specifies the listener ID.           |
| ener_id |          |         |                                      |
+---------+----------+---------+--------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------------+--------+-------------------------------------------------+
| Parameter     | Type   | Description                                     |
+===============+========+=================================================+
| up            | String | Specifies the time when the listener was        |
| date_time     |        | updated.                                        |
+---------------+--------+-------------------------------------------------+
| bac           | I      | Specifies the port used by backend ECSs.        |
| kend_port     | nteger |                                                 |
+---------------+--------+-------------------------------------------------+
| id            | String | Specifies the listener ID.                      |
+---------------+--------+-------------------------------------------------+
| backend       | String | Specifies the protocol used by backend ECSs.    |
| _protocol     |        |                                                 |
+---------------+--------+-------------------------------------------------+
| s             | String | Specifies where the cookie is from. The only    |
| ticky_ses     |        | value is **insert**, indicating that the cookie |
| sion_type     |        | is inserted by the load balancer.               |
|               |        |                                                 |
|               |        | -  This parameter is valid when **protocol** is |
|               |        |    set to **HTTP** and **session_sticky** to    |
|               |        |    **true**. The default value is **insert**.   |
|               |        |                                                 |
|               |        | -  This parameter is invalid when **protocol**  |
|               |        |    is set to **TCP**, which means that the      |
|               |        |    parameter is unavailable or its value is set |
|               |        |    to **null**.                                 |
+---------------+--------+-------------------------------------------------+
| de            | String | Provides supplementary information about the    |
| scription     |        | listener.                                       |
+---------------+--------+-------------------------------------------------+
| loadba        | String | Specifies the load balancer ID.                 |
| lancer_id     |        |                                                 |
+---------------+--------+-------------------------------------------------+
| cr            | String | Specifies the time when the listener was        |
| eate_time     |        | created.                                        |
+---------------+--------+-------------------------------------------------+
| status        | String | Specifies the listener status. The value can be |
|               |        | **ACTIVE**, **PENDING_CREATE**, or **ERROR**.   |
+---------------+--------+-------------------------------------------------+
| protocol      | String | Specifies the protocol used for load balancing  |
|               |        | at Layer 4 or Layer 7.                          |
+---------------+--------+-------------------------------------------------+
| port          | I      | Specifies the port used by the listener.        |
|               | nteger |                                                 |
+---------------+--------+-------------------------------------------------+
| cooki         | I      | -  Specifies the cookie timeout duration. This  |
| e_timeout     | nteger |    parameter is valid when **session_sticky**   |
|               |        |    is set to **true** and                       |
|               |        |    **sticky_session_type** to **insert**.       |
|               |        |                                                 |
|               |        | -  The value ranges from **1** to **1440**.     |
+---------------+--------+-------------------------------------------------+
| admin         | B      | -  Specifies the administrative status of the   |
| _state_up     | oolean |    load balancer.                               |
|               |        |                                                 |
|               |        | -  Two options are available:                   |
|               |        |                                                 |
|               |        | **false**: The load balancer is disabled.       |
|               |        |                                                 |
|               |        | **true**: The load balancer is running          |
|               |        | properly.                                       |
+---------------+--------+-------------------------------------------------+
| memb          | I      | Specifies the quantity of backend ECSs.         |
| er_number     | nteger |                                                 |
+---------------+--------+-------------------------------------------------+
| healt         | String | Specifies the health check ID.                  |
| hcheck_id     |        |                                                 |
+---------------+--------+-------------------------------------------------+
| sessi         | B      | Specifies whether to enable the sticky session  |
| on_sticky     | oolean | feature. The feature is enabled when the value  |
|               |        | is **true**.                                    |
+---------------+--------+-------------------------------------------------+
| lb_algorithm  | String | Specifies the load balancing algorithm.         |
|               |        |                                                 |
+---------------+--------+-------------------------------------------------+
| name          | String | Specifies the listener name.                    |
+---------------+--------+-------------------------------------------------+
| certi         | String | Specifies the ID of the SSL certificate for     |
| ficate_id     |        | security authentication.                        |
|               |        |                                                 |
|               |        | This parameter is mandatory when **protocol**   |
|               |        | is set to **HTTPS** or **SSL**. Otherwise, the  |
|               |        | parameter value is **null**.                    |
+---------------+--------+-------------------------------------------------+
| cer           | String | Lists the certificate IDs if **protocol** is    |
| tificates     |        | set to **HTTPS**.                               |
|               |        |                                                 |
|               |        | This parameter is mandatory in the SNI          |
|               |        | scenario.                                       |
+---------------+--------+-------------------------------------------------+
| tc            | I      | Specifies the TCP session timeout duration.     |
| p_timeout     | nteger |                                                 |
+---------------+--------+-------------------------------------------------+
| ud            | I      | Specifies the UDP session timeout duration.     |
| p_timeout     | nteger |                                                 |
+---------------+--------+-------------------------------------------------+
| ssl_protocols | String | Specifies the supported SSL/TLS protocol        |
|               |        | version. This parameter is available only when  |
|               |        | **protocol** is set to **HTTPS** or **SSL**.    |
|               |        |                                                 |
|               |        | NOTE                                            |
|               |        |                                                 |
|               |        | For HTTPS listeners in versions earlier than    |
|               |        | 1.2.8, the parameter value is **TLSv1.2**.      |
+---------------+--------+-------------------------------------------------+
| ss            | String | Specifies the cipher suite of an encryption     |
| l_ciphers     |        | protocol. This parameter is available only when |
|               |        | **protocol** is set to **HTTPS** or **SSL**.    |
+---------------+--------+-------------------------------------------------+

-  Example response

| {
| "update_time": "2015-09-15 07:41:17",
| "backend_port": 80,
| "id": "248425d7b97dc26920eb23720115e068",
| "backend_protocol": "TCP",
| "sticky_session_type": "insert",
| "description": "",
| "loadbalancer_id": "0b07acf06d243925bc24a0ac7445267a",
| "create_time": "2015-09-15 07:41:17",
| "status": "ACTIVE",
| "protocol": "TCP",
| "port": 88,
| "cookie_timeout": 100,
| "admin_state_up": true,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "lb_algorithm": "roundrobin",
| "name": "listener1",
| "tcp_draining": true,
| "tcp_draining_timeout": 5
| }

| {
| "update_time": "2016-12-01 07:12:59",
| "backend_port": 9090,
| "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
| "backend_protocol": "TCP",
| "sticky_session_type": null,
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "lb_algorithm": "roundrobin",
| "create_time": "2016-12-01 07:12:43",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "TCP",
| "cookie_timeout": 100,
| "port": 9092,
| "tcp_draining": 1,
| "tcp_timeout": 1,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| }

#. Status Code

-  Normal

200

-  Error

+--------+----------------------------+--------------------------------+
| Status | Message                    | Description                    |
| Code   |                            |                                |
+========+============================+================================+
| 400    | badRequest                 | Request error.                 |
+--------+----------------------------+--------------------------------+
| 401    | unauthorized               | Authentication failed.         |
+--------+----------------------------+--------------------------------+
| 403    | userDisabled               | You do not have the permission |
|        |                            | to perform the operation.      |
+--------+----------------------------+--------------------------------+
| 404    | Not Found                  | The requested page does not    |
|        |                            | exist.                         |
+--------+----------------------------+--------------------------------+
| 500    | authFault                  | System error.                  |
+--------+----------------------------+--------------------------------+
| 503    | serviceUnavailable         | The service is unavailable.    |
+--------+----------------------------+--------------------------------+

Querying Listeners
~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query listeners using search criteria and display
them in a list.

2. URI

GET
/v1.0/{project_id}/elbaas/listeners?loadbalancer_id={loadbalancer_id}

.. image:: /media/image2.png
   :width: 0.75in
   :height: 0.26042in

Enter a question mark (?) and an ampersand (&) at the end of the URI to
define multiple search criteria. You can filter the listeners using the
parameters in the response except **update_time**, **create_time**,
**admin_state_up**, **session_sticky**, and **member_number**.

1. Parameter description

+--------+--------+--------+-----------------------------------------+
| Par    | Man    | Type   | Description                             |
| ameter | datory |        |                                         |
+========+========+========+=========================================+
| proj   | Yes    | String | Specifies the project ID.               |
| ect_id |        |        |                                         |
+--------+--------+--------+-----------------------------------------+
| loa    | No     | String | Specifies the load balancer ID.         |
| dbalan |        |        |                                         |
| cer_id |        |        |                                         |
+--------+--------+--------+-----------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------------------+---------+--------------------------------------------------+
| Parameter           | Type    | Description                                      |
+=====================+=========+==================================================+
| update_time         | String  | Specifies the time when the listener was         |
|                     |         | updated.                                         |
+---------------------+---------+--------------------------------------------------+
| backend_port        | Integer | Specifies the port used by backend ECSs.         |
+---------------------+---------+--------------------------------------------------+
| id                  | String  | Specifies the listener ID.                       |
+---------------------+---------+--------------------------------------------------+
| backend_protocol    | String  | Specifies the protocol used by backend ECSs.     |
+---------------------+---------+--------------------------------------------------+
| sticky_session_type | String  | Specifies where the cookie is from. The only     |
|                     |         | value is **insert**, indicating that the cookie  |
|                     |         | is inserted by the load balancer.                |
|                     |         |                                                  |
|                     |         | -  This parameter is valid when **protocol** is  |
|                     |         |    set to **HTTP** and **session_sticky** to     |
|                     |         |    **true**. The default value is **insert**.    |
|                     |         |                                                  |
|                     |         | -  This parameter is invalid when **protocol**   |
|                     |         |    is set to **TCP**, which means that the       |
|                     |         |    parameter is unavailable or its value is set  |
|                     |         |    to **null**.                                  |
+---------------------+---------+--------------------------------------------------+
| desc                | String  | Provides supplementary information about the     |
| ription             |         | listener.                                        |
+---------------------+---------+--------------------------------------------------+
| l                   | String  | Specifies the load balancer ID.                  |
| oadbala             |         |                                                  |
| ncer_id             |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| crea                | String  | Specifies the time when the listener was         |
| te_time             |         | created.                                         |
+---------------------+---------+--------------------------------------------------+
| status              | String  | Specifies the listener status. The value can be  |
|                     |         | **ACTIVE**, **PENDING_CREATE**, or **ERROR**.    |
+---------------------+---------+--------------------------------------------------+
| p                   | String  | Specifies the protocol used for load balancing   |
| rotocol             |         | at Layer 4 or Layer 7.                           |
+---------------------+---------+--------------------------------------------------+
| lb_al               | String  | Specifies the load balancing algorithm.          |
| gorithm             |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| admin_s             | Boolean | -  Specifies the administrative status of the    |
| tate_up             |         |    load balancer.                                |
|                     |         |                                                  |
|                     |         | -  Two options are available:                    |
|                     |         |                                                  |
|                     |         | **false**: The load balancer is disabled.        |
|                     |         | **true**: The load balancer is running properly. |
+---------------------+---------+--------------------------------------------------+
| cookie_timeout      | Integer | -  Specifies the cookie timeout duration. This   |
|                     |         |    parameter is valid when **session_sticky** is |
|                     |         |    set to **true** and **sticky_session_type**   |
|                     |         |    to **insert**.                                |
|                     |         |                                                  |
|                     |         | -  The value ranges from **1** to **1440**.      |
+---------------------+---------+--------------------------------------------------+
| member              | Integer | Specifies the quantity of backend ECSs.          |
| _number             |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| healthc             | String  | Specifies the health check ID.                   |
| heck_id             |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| session             | Boolean | Specifies whether to enable the sticky session   |
| _sticky             |         | feature. The feature is enabled when the value   |
|                     |         | is **true**.                                     |
+---------------------+---------+--------------------------------------------------+
| port                | Integer | Specifies the port used by the listener.         |
+---------------------+---------+--------------------------------------------------+
| name                | String  | Specifies the listener name.                     |
+---------------------+---------+--------------------------------------------------+
| certifi             | String  | Specifies the ID of the SSL certificate for      |
| cate_id             |         | security authentication. This parameter is       |
|                     |         | mandatory when **protocol** is set to **HTTPS**  |
|                     |         | or **SSL**. Otherwise, the parameter value is    |
|                     |         | **null**.                                        |
+---------------------+---------+--------------------------------------------------+
| certi               | String  | Lists the certificate IDs if **protocol** is set |
| ficates             |         | to **HTTPS**.                                    |
|                     |         |                                                  |
|                     |         | This parameter is mandatory in the SNI scenario. |
+---------------------+---------+--------------------------------------------------+
| tcp_timeout         | Integer | Specifies the TCP session timeout duration.      |
|                     |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| udp_timeout         | Integer | Specifies the UDP session timeout duration.      |
|                     |         |                                                  |
+---------------------+---------+--------------------------------------------------+
| ssl_protocols       | String  | Specifies the supported SSL/TLS protocol         |
|                     |         | version. This parameter is available only when   |
|                     |         | **protocol** is set to **HTTPS** or **SSL**.     |
|                     |         |                                                  |
|                     |         | NOTE                                             |
|                     |         |                                                  |
|                     |         | For HTTPS listeners in versions earlier than     |
|                     |         | 1.2.8, the parameter value is **TLSv1.2**.       |
+---------------------+---------+--------------------------------------------------+
| ssl_ciphers         | String  | Specifies the cipher suite of an encryption      |
|                     |         | protocol. This parameter is available only when  |
|                     |         | **protocol** is set to **HTTPS** or **SSL**.     |
+---------------------+---------+--------------------------------------------------+

-  Example response

| [
| {
| "update_time": "2016-12-01 07:12:59",
| "backend_port": 9090,
| "id": "a824584fb3ba4d39ba0cf372c7cbbb67",
| "backend_protocol": "TCP",
| "sticky_session_type": null,
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "lb_algorithm": "roundrobin",
| "create_time": "2016-12-01 07:12:43",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "TCP",
| "cookie_timeout": 100,
| "port": 9092,
| "tcp_draining": true,
| "tcp_timeout": 1,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| },
| {
| "update_time": "2016-12-01 07:11:49",
| "backend_port": 9090,
| "id": "4818300858fc43e0a4d843ce74ee83a4",
| "backend_protocol": "HTTP",
| "sticky_session_type": "insert",
| "certificate_id": null,
| "description": "",
| "loadbalancer_id": "f54c65b1b5dd4a4f95b71b44796ac013",
| "lb_algorithm": "roundrobin",
| "create_time": "2016-12-01 07:11:30",
| "admin_state_up": false,
| "status": "ACTIVE",
| "protocol": "HTTP",
| "cookie_timeout": 100,
| "port": 9091,
| "tcp_draining": true,
| "tcp_timeout": null,
| "member_number": 0,
| "healthcheck_id": null,
| "session_sticky": true,
| "tcp_draining_timeout": 5,
| "name": "lis"
| }
| ]

#. Status Code

-  Normal

200

-  Error

+--------+----------------------------+--------------------------------+
| Status | Message                    | Description                    |
| Code   |                            |                                |
+========+============================+================================+
| 400    | badRequest                 | Request error.                 |
+--------+----------------------------+--------------------------------+
| 401    | unauthorized               | Authentication failed.         |
+--------+----------------------------+--------------------------------+
| 403    | userDisabled               | You do not have the permission |
|        |                            | to perform the operation.      |
+--------+----------------------------+--------------------------------+
| 404    | Not Found                  | The requested page does not    |
|        |                            | exist.                         |
+--------+----------------------------+--------------------------------+
| 500    | authFault                  | System error.                  |
+--------+----------------------------+--------------------------------+
| 503    | serviceUnavailable         | The service is unavailable.    |
+--------+----------------------------+--------------------------------+

Health Check
------------

1. .. rubric:: Configuring a Health Check
      :name: configuring-a-health-check

   #. Function

This API is used to configure a health check for backend ECSs.

2. URI

POST /v1.0/{project_id}/elbaas/healthcheck

1. Parameter description

+---------------------+--------+-------+----------------------------------------+
| Parameter           | Man    | Type  | Description                            |
|                     | datory |       |                                        |
+=====================+========+=======+========================================+
| p                   | Yes    | S     | Specifies the project ID.              |
| roject_id           |        | tring |                                        |
+---------------------+--------+-------+----------------------------------------+
| li                  | Yes    | S     | Specifies the ID of the listener with  |
| stener_id           |        | tring | which the health check is associated.  |
+---------------------+--------+-------+----------------------------------------+
| he                  | No     | S     | -  Specifies the health check          |
| althcheck           |        | tring |    protocol. A listener using UDP is   |
| _protocol           |        |       |    not allowed for a private network   |
|                     |        |       |    load balancer.                      |
|                     |        |       |                                        |
|                     |        |       | -  The value can be **HTTP**, **TCP**, |
|                     |        |       |    or **UDP**.                         |
+---------------------+--------+-------+----------------------------------------+
| health              | No     | S     | -  Specifies the health check URI.     |
| check_uri           |        | tring |    This parameter is valid when        |
|                     |        |       |    **healthcheck_protocol** is         |
|                     |        |       |    **HTTP**.                           |
|                     |        |       |                                        |
|                     |        |       | -  The value can contain 1 to 80       |
|                     |        |       |    characters that must start with a   |
|                     |        |       |    slash (/) and can contain only      |
|                     |        |       |    letters, digits, and special        |
|                     |        |       |    characters such as -/.%?#&_=        |
+---------------------+--------+-------+----------------------------------------+
| health              | No     | In    | -  Specifies the health check port.    |
| check_con           |        | teger |                                        |
| nect_port           |        |       | -  The port number ranges from 1 to    |
|                     |        |       |    65535.                              |
+---------------------+--------+-------+----------------------------------------+
| healthy_threshold   | No     | In    | -  Specifies the number of consecutive |
|                     |        | teger |    health checks when the health check |
|                     |        |       |    result of a backend ECS changes     |
|                     |        |       |    from **fail** to **success**.       |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **10**.                             |
+---------------------+--------+-------+----------------------------------------+
| unhealthy_threshold | No     | In    | -  Specifies the number of consecutive |
|                     |        | teger |    health checks when the health check |
|                     |        |       |    result of a backend ECS changes     |
|                     |        |       |    from **success** to **fail**.       |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **10**.                             |
+---------------------+--------+-------+----------------------------------------+
| halthcheck_timeout  | No     | In    | -  Specifies the maximum time required |
|                     |        | teger |    for waiting for a response from the |
|                     |        |       |    health check in the unit of second. |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **50**.                             |
+---------------------+--------+-------+----------------------------------------+
| he                  | No     | In    | -  Specifies the maximum time between  |
| althcheck           |        | teger |    health checks in the unit of        |
| _interval           |        |       |    second.                             |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **50**.                             |
+---------------------+--------+-------+----------------------------------------+

#. Request

-  Request parameters

None

-  Example request 1: Configuring an HTTP health check

| {
| "healthcheck_connect_port": 80,
| "healthcheck_interval": 5,
| "healthcheck_protocol": "HTTP",
| "healthcheck_timeout": 10,
| "healthcheck_uri": "/",
| "healthy_threshold": 3,
| "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
| "unhealthy_threshold": 3
| }

-  Example request 2: Configuring a TCP health check

| {
| "healthcheck_connect_port": 80,
| "healthcheck_interval": 5,
| "healthcheck_protocol": "TCP",
| "healthcheck_timeout": 10,
| "healthcheck_uri": "",
| "healthy_threshold": 3,
| "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
| "unhealthy_threshold": 3
| }

#. Response

-  Response parameters

   1. Parameter description

+--------------------------+---------+---------------------------------------------+
| Parameter                | Type    | Description                                 |
+==========================+=========+=============================================+
| healthch                 | Integer | Specifies the maximum time between health   |
| eck_interval             |         | checks in the unit of second.               |
+--------------------------+---------+---------------------------------------------+
| listener_id              | String  | Specifies the ID of the listener with which |
|                          |         | the health check is associated.             |
+--------------------------+---------+---------------------------------------------+
| id                       | String  | Specifies the health check ID.              |
+--------------------------+---------+---------------------------------------------+
| healthch                 | String  | Specifies the health check protocol.        |
| eck_protocol             |         |                                             |
+--------------------------+---------+---------------------------------------------+
| unhealt                  | Integer | Specifies the number of consecutive health  |
| hy_threshold             |         | checks when the health check result of a    |
|                          |         | backend ECS changes from **success** to     |
|                          |         | **fail**.                                   |
+--------------------------+---------+---------------------------------------------+
| update_time              | String  | Specifies the time when the health check    |
|                          |         | was updated.                                |
+--------------------------+---------+---------------------------------------------+
| create_time              | String  | Specifies the time when the health check    |
|                          |         | was configured.                             |
+--------------------------+---------+---------------------------------------------+
| healthcheck_connect_port | Integer | Specifies the health check port.            |
+--------------------------+---------+---------------------------------------------+
| healthc                  | Integer | Specifies the maximum time required for     |
| heck_timeout             |         | waiting for a response from the health      |
|                          |         | check in the unit of second.                |
+--------------------------+---------+---------------------------------------------+
| hea                      | String  | Specifies the health check URI. This        |
| lthcheck_uri             |         | parameter is valid when                     |
|                          |         | **healthcheck_protocol** is **HTTP**.       |
+--------------------------+---------+---------------------------------------------+
| healt                    | Integer | Specifies the number of consecutive health  |
| hy_threshold             |         | checks when the health check result of a    |
|                          |         | backend ECS changes from **fail** to        |
|                          |         | **success**.                                |
+--------------------------+---------+---------------------------------------------+

-  Example response 1: Configuring an HTTP health check

| {
| *"*\ healthcheck_interval\ *"*:5,
| "listener_id":"3ce8c4429478a5eb6ef4930de2d75b28",
| "id":"134e5ea962327c6a574b83e6e7f31f35",
| "healthcheck_protocol":"HTTP",
| "unhealthy_threshold":3,
| "update_time":"2015-12-25 03:57:23",
| "create_time":"2015-12-25 03:57:23",
| "healthcheck_connect_port":80,
| "healthcheck_timeout":10,
| "healthcheck_uri":"\/",
| "healthy_threshold":3
| }

-  Example response 2: Configuring a TCP health check

| {
| "healthcheck_interval":5,
| "listener_id":"3ce8c4429478a5eb6ef4930de2d75b28",
| "id":"134e5ea962327c6a574b83e6e7f31f35",
| "healthcheck_protocol":"TCP",
| "unhealthy_threshold":3,
| "update_time":"2015-12-25 03:57:23",
| "create_time":"2015-12-25 03:57:23",
| "healthcheck_connect_port":80,
| "healthcheck_timeout":10,
| "healthcheck_uri":"",
| "healthy_threshold":3
| }

#. Status Code

-  Normal

200

-  Error

+------+------------------------------+--------------------------------+
| St   | Message                      | Description                    |
| atus |                              |                                |
| Code |                              |                                |
+======+==============================+================================+
| 400  | badRequest                   | Request error.                 |
+------+------------------------------+--------------------------------+
| 401  | unauthorized                 | Authentication failed.         |
+------+------------------------------+--------------------------------+
| 403  | userDisabled                 | You do not have the permission |
|      |                              | to perform the operation.      |
+------+------------------------------+--------------------------------+
| 404  | Not Found                    | The requested page does not    |
|      |                              | exist.                         |
+------+------------------------------+--------------------------------+
| 500  | authFault                    | System error.                  |
+------+------------------------------+--------------------------------+
| 503  | serviceUnavailable           | The service is unavailable.    |
+------+------------------------------+--------------------------------+

Deleting a Health Check
~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to delete a health check.

2. URI

DELETE /v1.0/{project_id}/elbaas/healthcheck/{healthcheck_id}

1. Parameter description

+----------+----------+--------+--------------------------------------+
| P        | M        | Type   | Description                          |
| arameter | andatory |        |                                      |
+==========+==========+========+======================================+
| pr       | Yes      | String | Specifies the project ID.            |
| oject_id |          |        |                                      |
+----------+----------+--------+--------------------------------------+
| health   | Yes      | String | Specifies the health check ID.       |
| check_id |          |        |                                      |
+----------+----------+--------+--------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

None

-  Example response

None

#. Status Code

-  Normal

204

-  Error

+--------+----------------------------+--------------------------------+
| Status | Message                    | Description                    |
| Code   |                            |                                |
+========+============================+================================+
| 400    | badRequest                 | Request error.                 |
+--------+----------------------------+--------------------------------+
| 401    | unauthorized               | Authentication failed.         |
+--------+----------------------------+--------------------------------+
| 403    | userDisabled               | You do not have the permission |
|        |                            | to perform the operation.      |
+--------+----------------------------+--------------------------------+
| 404    | Not Found                  | The requested page does not    |
|        |                            | exist.                         |
+--------+----------------------------+--------------------------------+
| 500    | authFault                  | System error.                  |
+--------+----------------------------+--------------------------------+
| 503    | serviceUnavailable         | The service is unavailable.    |
+--------+----------------------------+--------------------------------+

Modifying a Health Check
~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to modify information about a health check.

2. URI

PUT /v1.0/{project_id}/elbaas/healthcheck/{healthcheck_id}

1. Parameter description

+---------------------+--------+-------+----------------------------------------+
| Parameter           | Man    | Type  | Description                            |
|                     | datory |       |                                        |
+=====================+========+=======+========================================+
| p                   | Yes    | S     | Specifies the project ID.              |
| roject_id           |        | tring |                                        |
+---------------------+--------+-------+----------------------------------------+
| healt               | Yes    | S     | Specifies the health check ID.         |
| hcheck_id           |        | tring |                                        |
+---------------------+--------+-------+----------------------------------------+
| he                  | No     | S     | -  Specifies the health check          |
| althcheck           |        | tring |    protocol.                           |
| _protocol           |        |       |                                        |
|                     |        |       | -  The value can be **HTTP** or        |
|                     |        |       |    **TCP** (case-insensitive).         |
+---------------------+--------+-------+----------------------------------------+
| health              | No     | S     | -  Specifies the health check URI.     |
| check_uri           |        | tring |    This parameter is valid when        |
|                     |        |       |    **healthcheck_protocol** is         |
|                     |        |       |    **HTTP**.                           |
|                     |        |       |                                        |
|                     |        |       | -  The value can contain 1 to 80       |
|                     |        |       |    characters that must start with a   |
|                     |        |       |    slash (/) and can contain only      |
|                     |        |       |    letters, digits, and special        |
|                     |        |       |    characters such as -/.%?#&_=        |
+---------------------+--------+-------+----------------------------------------+
| health              | No     | In    | -  Specifies the health check port.    |
| check_con           |        | teger |                                        |
| nect_port           |        |       | -  The port number ranges from 1 to    |
|                     |        |       |    65535.                              |
+---------------------+--------+-------+----------------------------------------+
| healthy_threshold   | No     | In    | -  Specifies the number of consecutive |
|                     |        | teger |    health checks when the health check |
|                     |        |       |    result of a backend ECS changes     |
|                     |        |       |    from **fail** to **success**.       |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **10**.                             |
+---------------------+--------+-------+----------------------------------------+
| unhealthy_threshold | No     | In    | -  Specifies the number of consecutive |
|                     |        | teger |    health checks when the health check |
|                     |        |       |    result of a backend ECS changes     |
|                     |        |       |    from **success** to **fail**.       |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **10**.                             |
+---------------------+--------+-------+----------------------------------------+
| h                   | No     | In    | -  Specifies the maximum time required |
| ealthchec           |        | teger |    for waiting for a response from the |
| k_timeout           |        |       |    health check in the unit of second. |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **50**.                             |
+---------------------+--------+-------+----------------------------------------+
| he                  | No     | In    | -  Specifies the maximum time between  |
| althcheck           |        | teger |    health checks in the unit of        |
| _interval           |        |       |    second.                             |
|                     |        |       |                                        |
|                     |        |       | -  The value ranges from **1** to      |
|                     |        |       |    **50**.                             |
+---------------------+--------+-------+----------------------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "healthcheck_connect_port": 88,
| "healthcheck_interval": 5,
| "healthcheck_protocol": "HTTP",
| "healthcheck_timeout": 10,
| "healthcheck_uri": "/",
| "healthy_threshold": 3,
| "unhealthy_threshold": 2
| }

#. Response

-  Response parameters

   1. Parameter description

+------------+---------+-----------------------------------------------+
| Parameter  | Type    | Description                                   |
+============+=========+===============================================+
| healthchec | Integer | Specifies the maximum time between health     |
| k_interval |         | checks in the unit of second.                 |
+------------+---------+-----------------------------------------------+
| l          | String  | Specifies the ID of the listener with which   |
| istener_id |         | the health check is associated.               |
+------------+---------+-----------------------------------------------+
| id         | String  | Specifies the health check ID.                |
+------------+---------+-----------------------------------------------+
| healthchec | String  | Specifies the health check protocol.          |
| k_protocol |         |                                               |
+------------+---------+-----------------------------------------------+
| unhealthy  | Integer | Specifies the number of consecutive health    |
| _threshold |         | checks when the health check result of a      |
|            |         | backend ECS changes from **success** to       |
|            |         | **fail**.                                     |
+------------+---------+-----------------------------------------------+
| u          | String  | Specifies the time when the certificate was   |
| pdate_time |         | updated.                                      |
+------------+---------+-----------------------------------------------+
| c          | String  | Specifies the time when the health check was  |
| reate_time |         | created.                                      |
+------------+---------+-----------------------------------------------+
| heal       | Integer | Specifies the health check port.              |
| thcheck_co |         |                                               |
| nnect_port |         |                                               |
+------------+---------+-----------------------------------------------+
| healthche  | Integer | Specifies the maximum time required for       |
| ck_timeout |         | waiting for a response from the health check  |
|            |         | in the unit of second.                        |
+------------+---------+-----------------------------------------------+
| healt      | String  | Specifies the health check URI. This          |
| hcheck_uri |         | parameter is valid when                       |
|            |         | **healthcheck_protocol** is **HTTP**.         |
+------------+---------+-----------------------------------------------+
| healthy    | Integer | Specifies the threshold at which the health   |
| _threshold |         | check result is **success**, that is, the     |
|            |         | number of consecutive successful health       |
|            |         | checks when the health check result of a      |
|            |         | backend ECS changes from **fail** to          |
|            |         | **success**.                                  |
+------------+---------+-----------------------------------------------+

-  Example response

| {
| "healthcheck_interval": 5,
| "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
| "id": "134e5ea962327c6a574b83e6e7f31f35",
| "healthcheck_protocol": "HTTP",
| "unhealthy_threshold": 2,
| "update_time": "2015-12-25 03:57:23",
| "create_time": "2015-12-25 03:57:23",
| "healthcheck_connect_port": 88,
| "healthcheck_timeout": 10,
| "healthcheck_uri": "/",
| "healthy_threshold": 3
| }

#. Status Code

-  Normal

200

-  Error

+-------+----------------------------+--------------------------------+
| S     | Message                    | Description                    |
| tatus |                            |                                |
| Code  |                            |                                |
+=======+============================+================================+
| 400   | badRequest                 | Request error.                 |
+-------+----------------------------+--------------------------------+
| 401   | unauthorized               | Authentication failed.         |
+-------+----------------------------+--------------------------------+
| 403   | userDisabled               | You do not have the permission |
|       |                            | to perform the operation.      |
+-------+----------------------------+--------------------------------+
| 404   | Not Found                  | The requested page does not    |
|       |                            | exist.                         |
+-------+----------------------------+--------------------------------+
| 500   | authFault                  | System error.                  |
+-------+----------------------------+--------------------------------+
| 503   | serviceUnavailable         | The service is unavailable.    |
+-------+----------------------------+--------------------------------+

Querying Details of a Health Check
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query details about a health check.

2. URI

GET /v1.0/{project_id}/elbaas/healthcheck/{healthcheck_id}

1. Parameter description

+----------+----------+--------+--------------------------------------+
| P        | M        | Type   | Description                          |
| arameter | andatory |        |                                      |
+==========+==========+========+======================================+
| pr       | Yes      | String | Specifies the project ID.            |
| oject_id |          |        |                                      |
+----------+----------+--------+--------------------------------------+
| health   | Yes      | String | Specifies the health check ID.       |
| check_id |          |        |                                      |
+----------+----------+--------+--------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+------------+---------+----------------------------------------------+
| Parameter  | Type    | Description                                  |
+============+=========+==============================================+
| healthchec | Integer | Specifies the maximum time between health    |
| k_interval |         | checks in the unit of second.                |
+------------+---------+----------------------------------------------+
| l          | String  | Specifies the ID of the listener with which  |
| istener_id |         | the health check is associated.              |
+------------+---------+----------------------------------------------+
| id         | String  | Specifies the health check ID.               |
+------------+---------+----------------------------------------------+
| healthchec | String  | Specifies the health check protocol.         |
| k_protocol |         |                                              |
+------------+---------+----------------------------------------------+
| unhealthy  | Integer | Specifies the number of consecutive health   |
| _threshold |         | checks when the health check result of a     |
|            |         | backend ECS changes from **success** to      |
|            |         | **fail**.                                    |
+------------+---------+----------------------------------------------+
| u          | String  | Specifies the time when the health check was |
| pdate_time |         | updated.                                     |
+------------+---------+----------------------------------------------+
| c          | String  | Specifies the time when the health check was |
| reate_time |         | configured.                                  |
+------------+---------+----------------------------------------------+
| heal       | Integer | Specifies the health check port.             |
| thcheck_co |         |                                              |
| nnect_port |         |                                              |
+------------+---------+----------------------------------------------+
| healthche  | Integer | Specifies the maximum time required for      |
| ck_timeout |         | waiting for a response from the health check |
|            |         | in the unit of second.                       |
+------------+---------+----------------------------------------------+
| healt      | String  | Specifies the health check URI. This         |
| hcheck_uri |         | parameter is valid when                      |
|            |         | **healthcheck_protocol** is **HTTP**.        |
+------------+---------+----------------------------------------------+
| healthy    | Integer | Specifies the threshold at which the health  |
| _threshold |         | check result is **success**, that is, the    |
|            |         | number of consecutive successful health      |
|            |         | checks when the health check result of a     |
|            |         | backend ECS changes from **fail** to         |
|            |         | **success**.                                 |
+------------+---------+----------------------------------------------+

-  Example response

| {
| "healthcheck_interval": 5,
| "listener_id": "3ce8c4429478a5eb6ef4930de2d75b28",
| "id": "134e5ea962327c6a574b83e6e7f31f35",
| "healthcheck_protocol": "HTTP",
| "unhealthy_threshold": 2,
| "update_time": "2015-12-25 03:57:23",
| "create_time": "2015-12-25 03:57:23",
| "healthcheck_connect_port": 88,
| "healthcheck_timeout": 10,
| "healthcheck_uri": "/",
| "healthy_threshold": 3
| }

#. Status Code

-  Normal

200

-  Error

+------+------------------------------+--------------------------------+
| St   | Message                      | Description                    |
| atus |                              |                                |
| Code |                              |                                |
+======+==============================+================================+
| 400  | badRequest                   | Request error.                 |
+------+------------------------------+--------------------------------+
| 401  | unauthorized                 | Authentication failed.         |
+------+------------------------------+--------------------------------+
| 403  | userDisabled                 | You do not have the permission |
|      |                              | to perform the operation.      |
+------+------------------------------+--------------------------------+
| 404  | Not Found                    | The requested page does not    |
|      |                              | exist.                         |
+------+------------------------------+--------------------------------+
| 500  | authFault                    | System error.                  |
+------+------------------------------+--------------------------------+
| 503  | serviceUnavailable           | The service is unavailable.    |
+------+------------------------------+--------------------------------+

Backend ECS
-----------

1. .. rubric:: Adding Backend ECSs
      :name: adding-backend-ecss

   #. Function

This API is used to add backend ECSs to a listener for monitoring.

To add backend ECSs to a UDP listener, IP addresses can be pinged and
UDP services must be enabled.

2. URI

POST /v1.0/{project_id}/elbaas/listeners/{listener_id}/members

1. Parameter description

+---------+---------+--------+----------------------------------------+
| Pa      | Ma      | Type   | Description                            |
| rameter | ndatory |        |                                        |
+=========+=========+========+========================================+
| pro     | Yes     | String | Specifies the project ID.              |
| ject_id |         |        |                                        |
+---------+---------+--------+----------------------------------------+
| list    | Yes     | String | Specifies the listener ID.             |
| ener_id |         |        |                                        |
+---------+---------+--------+----------------------------------------+
| se      | Yes     | String | Specifies the backend ECS ID.          |
| rver_id |         |        |                                        |
+---------+---------+--------+----------------------------------------+
| address | Yes     | String | Specifies the private IP address of    |
|         |         |        | the backend ECS.                       |
+---------+---------+--------+----------------------------------------+

3. Request

-  Request parameters

None

-  Example request

| [
| {
| "server_id": "dbecb618-2259-405f-ab17-9b68c4f541b0",
| "address": "172.16.0.31"
| }
| ]

#. Response

-  Response parameters

   1. Parameter description

+----------+---------+-------------------------------------------------+
| P        | Type    | Description                                     |
| arameter |         |                                                 |
+==========+=========+=================================================+
| uri      | String  | Specifies the URI of the job for adding a       |
|          |         | backend ECS. It is returned by Combined API.    |
+----------+---------+-------------------------------------------------+
| job_id   | String  | Specifies the unique ID assigned to the job for |
|          |         | adding a backend ECS in Combined API.           |
+----------+---------+-------------------------------------------------+

-  Example response

| {
| "uri":
  "/v1/55300f3c8f764c06b1a32e2302edc305/jobs/4010b39b4fd3d5ff014fd3ec3ed8002d",
| "job_id": "4010b39b4fd3d5ff014fd3ec3ed8002d"
| }

#. Status Code

-  Normal

200

-  Error

+-------+----------------------------+--------------------------------+
| S     | Message                    | Description                    |
| tatus |                            |                                |
| Code  |                            |                                |
+=======+============================+================================+
| 400   | badRequest                 | Request error.                 |
+-------+----------------------------+--------------------------------+
| 401   | unauthorized               | Authentication failed.         |
+-------+----------------------------+--------------------------------+
| 403   | userDisabled               | You do not have the permission |
|       |                            | to perform the operation.      |
+-------+----------------------------+--------------------------------+
| 404   | Not Found                  | The requested page does not    |
|       |                            | exist.                         |
+-------+----------------------------+--------------------------------+
| 500   | authFault                  | System error.                  |
+-------+----------------------------+--------------------------------+
| 503   | serviceUnavailable         | The service is unavailable.    |
+-------+----------------------------+--------------------------------+

Removing Backend ECSs
~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to remove backend ECSs from a listener. Multiple
backend ECSs can be removed concurrently.

2. URI

POST /v1.0/{project_id}/elbaas/listeners/{listener_id}/members/action

1. Parameter description

+---------+--------+-----------+--------------------------------------+
| Pa      | Man    | Type      | Description                          |
| rameter | datory |           |                                      |
+=========+========+===========+======================================+
| pro     | Yes    | String    | Specifies the project ID.            |
| ject_id |        |           |                                      |
+---------+--------+-----------+--------------------------------------+
| list    | Yes    | String    | Specifies the listener ID.           |
| ener_id |        |           |                                      |
+---------+--------+-----------+--------------------------------------+
| remov   | Yes    | Array     | Lists the removed backend ECSs.      |
| eMember |        |           |                                      |
+---------+--------+-----------+--------------------------------------+

2. **removeMember** parameter description

+---------+---------+----------+---------------------------------------+
| Pa      | Ma      | Type     | Description                           |
| rameter | ndatory |          |                                       |
+=========+=========+==========+=======================================+
| id      | Yes     | String   | Specifies the backend ECS ID.         |
+---------+---------+----------+---------------------------------------+

3. Request

-  Request parameters

None

-  Example request

| {
| "removeMember": [
| {
| "id": "34695d664b182fa69b98228032b0e239"
| }
| ]
| }

#. Response

-  Response parameters

   1. Parameter description

+---------+--------+--------------------------------------------------+
| Pa      | Type   | Description                                      |
| rameter |        |                                                  |
+=========+========+==================================================+
| uri     | String | Specifies the URI returned by Combined API after |
|         |        | the job for removing a backend ECS is delivered. |
+---------+--------+--------------------------------------------------+
| job_id  | String | Specifies the unique ID assigned to the job for  |
|         |        | removing a backend ECS in Combined API.          |
+---------+--------+--------------------------------------------------+

-  Example response

| {
| "uri":
  "/v1/55300f3c8f764c06b1a32e2302edc305/jobs/4010b39b4fd3d5ff014fd3f160fd006c",
| "job_id": "4010b39b4fd3d5ff014fd3f160fd006c"
| }

#. Status Code

-  Normal

200

-  Error

+-------------------+----------------+--------------------------------+
| Status Code       | Message        | Description                    |
+===================+================+================================+
| 400               | badRequest     | Request error.                 |
+-------------------+----------------+--------------------------------+
| 401               | unauthorized   | Authentication failed.         |
+-------------------+----------------+--------------------------------+
| 403               | userDisabled   | You do not have the permission |
|                   |                | to perform the operation.      |
+-------------------+----------------+--------------------------------+
| 404               | Not Found      | The requested page does not    |
|                   |                | exist.                         |
+-------------------+----------------+--------------------------------+
| 500               | authFault      | System error.                  |
+-------------------+----------------+--------------------------------+
| 503               | serv           | The service is unavailable.    |
|                   | iceUnavailable |                                |
+-------------------+----------------+--------------------------------+

Querying Backend ECSs
~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query backend ECSs added to a listener. If you are
the administrator, the backend ECS list will be empty.

2. URI

GET
/v1.0/{project_id}/elbaas/listeners/{listener_id}/members?limit=10&marker=0

.. image:: /media/image2.png
   :width: 0.75in
   :height: 0.26042in

Enter a question mark (?) and an ampersand (&) at the end of the URI to
define multiple search criteria. This API allows filtering backend ECSs
by each parameter in the response message except **listeners**,
**server_name**, **update_time**, and **create_time**.

1. Parameter description

+---------------------+-------------+-----------+---------------------+
| Parameter           | Mandatory   | Type      | Description         |
+=====================+=============+===========+=====================+
| project_id          | Yes         | String    | Specifies the       |
|                     |             |           | project ID.         |
+---------------------+-------------+-----------+---------------------+
| listener_id         | Yes         | String    | Specifies the       |
|                     |             |           | listener ID.        |
+---------------------+-------------+-----------+---------------------+
| marker              | No          | String    | Specifies the       |
|                     |             |           | resource ID of      |
|                     |             |           | pagination query.   |
|                     |             |           | If the parameter is |
|                     |             |           | left blank, only    |
|                     |             |           | resources on the    |
|                     |             |           | first page are      |
|                     |             |           | queried.            |
+---------------------+-------------+-----------+---------------------+
| limit               | No          | Integer   | Specifies the       |
|                     |             |           | number of records   |
|                     |             |           | on each page.       |
+---------------------+-------------+-----------+---------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+------------------+-----------------+--------------------------------+
| Parameter        | Type            | Description                    |
+==================+=================+================================+
| server_address   | String          | Specifies the private IP       |
|                  |                 | address of the backend ECS.    |
+------------------+-----------------+--------------------------------+
| id               | String          | Specifies the backend ECS ID.  |
+------------------+-----------------+--------------------------------+
| address          | String          | Specifies the floating IP      |
|                  |                 | address assigned to the        |
|                  |                 | backend ECS.                   |
+------------------+-----------------+--------------------------------+
| status           | String          | Specifies the status of the    |
|                  |                 | backend ECS. The value can be  |
|                  |                 | **ACTIVE**, **PENDING**, or    |
|                  |                 | **ERROR**.                     |
+------------------+-----------------+--------------------------------+
| health_status    | String          | Specifies the health check     |
|                  |                 | result. The value is           |
|                  |                 | **NORMAL**, **ABNORMAL**, or   |
|                  |                 | **UNAVAILABLE**.               |
+------------------+-----------------+--------------------------------+
| update_time      | String          | Specifies the time when the    |
|                  |                 | backend ECS was updated.       |
+------------------+-----------------+--------------------------------+
| create_time      | String          | Specifies the time when the    |
|                  |                 | backend ECS was added.         |
+------------------+-----------------+--------------------------------+
| server_name      | String          | Specifies the backend ECS      |
|                  |                 | name.                          |
+------------------+-----------------+--------------------------------+
| server_id        | String          | Specifies the backend ECS ID.  |
+------------------+-----------------+--------------------------------+
| listeners        | Array           | Specifies the listener with    |
|                  |                 | which the backend ECS is       |
|                  |                 | associated.                    |
+------------------+-----------------+--------------------------------+

2. **listeners** parameter description

+------------------+------------------+--------------------------------+
| Parameter        | Type             | Description                    |
+==================+==================+================================+
| id               | String           | Specifies the listener with    |
|                  |                  | which the backend ECS is       |
|                  |                  | associated.                    |
+------------------+------------------+--------------------------------+

-  Example response

| [
| {
| "server_address": "172.16.0.16",
| "id": "4ac8777333bc20777147ab160ea61baf",
| "status": "ACTIVE",
| "address": "100.64.27.96",
| "listeners": [
| {
| "id": "65093734fb966b3d70f6af26cc63e125"
| },
| {
| "id": "a659fe780a542e1adf204db767a021a3"
| }
| ],
| "update_time": "2015-12-28 10:35:51",
| "create_time": "2015-12-28 10:35:50",
| "server_name": null,
| "server_id": "97444148-7afb-47cc-b4a3-6e1c94d1ade4",
| "health_status": "NORMAL"
| },
| {
| "server_address": "172.16.0.15",
| "id": "d8a21f107a19d7bd1d05a1f764eb623a",
| "status": "ACTIVE",
| "address": "100.64.27.95",
| "listeners": [
| {
| "id": "65093734fb966b3d70f6af26cc63e125"
| },
| {
| "id": "a659fe780a542e1adf204db767a021a3"
| }
| ],
| "update_time": "2015-12-28 10:35:51",
| "create_time": "2015-12-28 10:35:50",
| "server_name": null,
| "server_id": "05b731db-d457-41dc-a824-862daba91a59",
| "health_status": "ABNORMAL"
| }
| ]

#. Status Code

-  Normal

200

-  Error

+-------+-----------------------------+--------------------------------+
| S     | Message                     | Description                    |
| tatus |                             |                                |
| Code  |                             |                                |
+=======+=============================+================================+
| 400   | badRequest                  | Request error.                 |
+-------+-----------------------------+--------------------------------+
| 401   | unauthorized                | Authentication failed.         |
+-------+-----------------------------+--------------------------------+
| 403   | userDisabled                | You do not have the permission |
|       |                             | to perform the operation.      |
+-------+-----------------------------+--------------------------------+
| 404   | Not Found                   | The requested page does not    |
|       |                             | exist.                         |
+-------+-----------------------------+--------------------------------+
| 500   | authFault                   | System error.                  |
+-------+-----------------------------+--------------------------------+
| 503   | serviceUnavailable          | The service is unavailable.    |
+-------+-----------------------------+--------------------------------+

Quota
-----

1. .. rubric:: Querying Load Balancer or Listener Quotas
      :name: querying-load-balancer-or-listener-quotas

   #. Function

This API is used to query the load balancer or listener quotas.

2. URI

GET /v1.0/{project_id}/elbaas/quotas

1. Parameter description

+----------+-----------+-------+--------------------------------------+
| P        | Mandatory | Type  | Description                          |
| arameter |           |       |                                      |
+==========+===========+=======+======================================+
| pr       | Yes       | S     | Specifies the project ID.            |
| oject_id |           | tring |                                      |
+----------+-----------+-------+--------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+---------+--------------+---------------------------------------------+
| Pa      | Type         | Description                                 |
| rameter |              |                                             |
+=========+==============+=============================================+
| quotas  | Object       | Specifies the resource quotas.              |
+---------+--------------+---------------------------------------------+

2. **quotas** parameter description

+---------+--------------+---------------------------------------------+
| Pa      | Type         | Description                                 |
| rameter |              |                                             |
+=========+==============+=============================================+
| re      | Array        | Lists the resource quotas.                  |
| sources |              |                                             |
+---------+--------------+---------------------------------------------+

3. **resources** parameter description

+----------+-------------+---------------------------------------------+
| P        | Type        | Description                                 |
| arameter |             |                                             |
+==========+=============+=============================================+
| type     | String      | Specifies the resource type. The value can  |
|          |             | be **elb** or **listener**.                 |
+----------+-------------+---------------------------------------------+
| used     | Integer     | Specifies the quantity of used resources.   |
+----------+-------------+---------------------------------------------+
| quota    | Integer     | Specifies the total resource quotas.        |
+----------+-------------+---------------------------------------------+
| max      | Integer     | Specifies the maximum number of resources.  |
+----------+-------------+---------------------------------------------+
| min      | Integer     | Specifies the minimum number of resources.  |
+----------+-------------+---------------------------------------------+

-  Example response

| {
| "quotas": {
| "resources": [
| {
| "type": "elb",
| "used": 2,
| "quota": 5,
| "max": 100,
| "min": 1
| },
| {
| "type": "listener",
| "quota": 5,
| "max": 200,
| "min": 1
| }
| ]
| }
| }

.. image:: /media/image2.png
   :width: 0.75in
   :height: 0.26042in

The **used** parameter is unavailable for listeners, for which an empty
character string is returned.

#. Status Code

-  Normal

200

-  Error

+------+------------------------------+--------------------------------+
| St   | Message                      | Description                    |
| atus |                              |                                |
| Code |                              |                                |
+======+==============================+================================+
| 400  | badRequest                   | Request error.                 |
+------+------------------------------+--------------------------------+
| 401  | unauthorized                 | Authentication failed.         |
+------+------------------------------+--------------------------------+
| 403  | userDisabled                 | You do not have the permission |
|      |                              | to perform the operation.      |
+------+------------------------------+--------------------------------+
| 404  | Not Found                    | The requested page does not    |
|      |                              | exist.                         |
+------+------------------------------+--------------------------------+
| 500  | authFault                    | System error.                  |
+------+------------------------------+--------------------------------+
| 503  | serviceUnavailable           | The service is unavailable.    |
+------+------------------------------+--------------------------------+

Certificate
-----------

1. .. rubric:: Creating a Certificate
      :name: creating-a-certificate

   #. Function

This API is used to create a certificate for an HTTPS listener.

2. URI

POST /v1.0/{project_id}/elbaas/certificate

1. Parameter description

+-------+---------+------+--------------------------------------------+
| Para  | Ma      | Type | Description                                |
| meter | ndatory |      |                                            |
+=======+=========+======+============================================+
| proje | Yes     | St   | Specifies the project ID.                  |
| ct_id |         | ring |                                            |
+-------+---------+------+--------------------------------------------+
| name  | No      | St   | -  Specifies the certificate name.         |
|       |         | ring |                                            |
|       |         |      | -  The value can contain 0 to 64           |
|       |         |      |    characters that consist of letters,     |
|       |         |      |    digits, underscores (_), and hyphens    |
|       |         |      |    (-).                                    |
+-------+---------+------+--------------------------------------------+
| d     | No      | St   | -  Provides supplementary information      |
| escri |         | ring |    about the certificate.                  |
| ption |         |      |                                            |
|       |         |      | -  The value contains a maximum of 128     |
|       |         |      |    characters and cannot contain angle     |
|       |         |      |    brackets (< and >).                     |
+-------+---------+------+--------------------------------------------+
| d     | No      | St   | -  Specifies the domain name associated    |
| omain |         | ring |    with the server certificate.            |
|       |         |      |                                            |
|       |         |      | -  The value can contain a maximum of 254  |
|       |         |      |    characters that consist of letters,     |
|       |         |      |    digits, hyphens (-), and periods (.),   |
|       |         |      |    and must start with uppercase letters   |
|       |         |      |    or digits.                              |
+-------+---------+------+--------------------------------------------+
| c     | Yes     | St   | -  Specifies the certificate content.      |
| ertif |         | ring |                                            |
| icate |         |      | -  The value is in PEM coding format.      |
+-------+---------+------+--------------------------------------------+
| p     | Yes     | St   | -  Specifies the private key of the        |
| rivat |         | ring |    certificate.                            |
| e_key |         |      |                                            |
|       |         |      | -  The value is in PEM coding format.      |
+-------+---------+------+--------------------------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "name": "cert-bky",
| "description": "certificate",
| "certificate": "-----BEGIN
  CERTIFICATE-----\nMIIDXTCCAkWgAwIBAgIJANoPUy2NktS6MA0GCSqGSIb3DQEBBQUAMEUxCzAJBgNV\nBAYTAkFVMRMwEQYDVQQIDApTb21lLVN0YXRlMSEwHwYDVQQKDBhJbnRlcm5ldCBX\naWRnaXRzIFB0eSBMdGQwHhcNMTYwNjIyMDMyOTU5WhcNMTkwNjIyMDMyOTU5WjBF\nMQswCQYDVQQGEwJBVTETMBEGA1UECAwKU29tZS1TdGF0ZTEhMB8GA1UECgwYSW50\nZXJuZXQgV2lkZ2l0cyBQdHkgTHRkMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\nCgKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP64DjDPny9\n+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQhIOIaP1Y\nNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcsS5v3kw88\n9gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39cHX/NpIHC\nHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTams0ThvSlZ\no6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABo1AwTjAdBgNVHQ4EFgQUlXhcABza\n2SdXPYpp8RkWvKblCNIwHwYDVR0jBBgwFoAUlXhcABza2SdXPYpp8RkWvKblCNIw\nDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQUFAAOCAQEAHmsFDOwbkD45PF4oYdX+\ncCoEGNjsLfi0spJ6b1CHQMEy2tPqYZJh8nGuUtB9Zd7+rbwm6NS38eGQVA5vbWZH\nMk+uq5un7YFwkM+fdjgCxbe/3PMkk/ZDYPHhpc1W8e/+aZVUBB2EpfzBC6tcP/DV\nSsjq+tG+JZIVADMxvEqVIF94JMpuY7o6U74SnUUrAi0h9GkWmeYh/Ucb3PLMe5sF\noZriRdAKc96KB0eUphfWZNtptOCqV6qtYqZZ/UCotp99xzrDkf8jGkm/iBljxb+v\n0NTg8JwfmykCj63YhTKpHf0+N/EK5yX1KUYtlkLaf8OPlsp/1lqAL6CdnydGEd/s\nAA==\n-----END
  CERTIFICATE-----",
| "private_key": "-----BEGIN RSA PRIVATE
  KEY-----\nMIIEpAIBAAKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP6\n4DjDPny9+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQ\nhIOIaP1YNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcs\nS5v3kw889gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39c\nHX/NpIHCHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTam\ns0ThvSlZo6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABAoIBACV47rpHuxEza24O\nevbbFI9OQIcs8xA26dN1j/+HpAkzinB4o5V+XOWWZDQwbYu58hYE4NYjqf6AxHk3\nOCqAA9yKH2NXhSEyLkP7/rKDF7geZg/YtwNiR/NXTJbNXl4p8VTaVvAq3yey188x\nJCMrd1yWSsOWD2Qw7iaIBpqQIzdEovPE4CG6GmaIRSuqYuoCfbVTFa6YST7jmOTv\nEpG+x6yJZzJ4o0vvfKbKfvPmQizjL+3nAW9g+kgXJmA1xTujiky7bzm2sLK2Slrx\n5rY73mXMElseSlhkYzWwyRmC6M+rWALXqOhVDgIGbaBV4IOzuyH/CUt0wy3ZMIpv\nMOWMNoECgYEA1LHsepCmwjlDF3yf/OztCr/DYqM4HjAY6FTmH+xz1Zjd5R1XOq60\nYFRkhs/e2D6M/gSX6hMqS9sCkg25yRJk3CsPeoS9v5MoiZQA8XlQNovcpWUI2DCm\naZRIsdovFgIqMHYh/Y4CYouee7Nz7foICzO9svrYrbOIVmMwDVJ8vzMCgYEA0ebg\nm0lCuOunyxaSBqOv4Q4sk7Ix0702dIrW0tsUJyU+xuXYH1P/0m+t4/KUU2cNwsg3\njiNzQR9QKvF8yTB5TB4Ye/9dKlu+BEOskvCpuErxc6iVJ+TZOrQDDPNcq56qez5b\nvv9EDdgzpjkjO+hS1j3kYOuG11hrP4Pox4PijqECgYEAz6RTZORKqFoWsZss5VK3\np0LGkEkfw/jYmBgqAQhpnSD7n20hd1yPI2vAKAxPVXTbWDFLzWygYiWRQNy9fxrB\n9F7lYYqtY5VagdVHhnYUZOvtoFoeZFA6ZeAph9elGCtM3Lq3PD2i/mmncsQibTUn\nHSiKDWzuk8UtWIjEpHze5BkCgYEAifD9eG+bzqTnn1qU2pIl2nQTLXj0r97v84Tu\niqF4zAT5DYMtFeGBBI1qLJxVh7342CH2CI4ZhxmJ+L68sAcQH8rDcnGui1DBPlIv\nDl3kW3280bJfW1lUvPRh8NfZ9dsO1HF1n75nveVwg/OWyR7zmWIRPPRrqAeua45H\nox5z/CECgYBqwlEBjue8oOkVVu/lKi6fo6jr+0u25K9dp9azHYwE0KNHX0MwRALw\nWbPgcjge23sfhbeqVvHo0JYBdRsk/OBuW73/9Sb5E+6auDoubCjC0cAIvs23MPju\nsMvKak4mQkI19foRXBydB/DDkK26iei/l0xoygrw50v2HErsQ7JcHw==\n-----END
  RSA PRIVATE KEY-----"
| }

#. Response

-  Response parameters

   1. Response parameters

+-----------+-----------+---------------------------------------------+
| Parameter | Type      | Description                                 |
+===========+===========+=============================================+
| tenant_id | String    | Specifies the project ID.                   |
+-----------+-----------+---------------------------------------------+
| id        | String    | Specifies the certificate ID.               |
+-----------+-----------+---------------------------------------------+
| name      | String    | Specifies the certificate name.             |
+-----------+-----------+---------------------------------------------+
| de        | String    | Provides supplementary information about    |
| scription |           | the certificate.                            |
+-----------+-----------+---------------------------------------------+
| domain    | String    | Specifies the domain name associated with   |
|           |           | the server certificate.                     |
+-----------+-----------+---------------------------------------------+
| ce        | String    | Specifies the certificate content.          |
| rtificate |           |                                             |
+-----------+-----------+---------------------------------------------+
| pr        | String    | Specifies the private key of the            |
| ivate_key |           | certificate.                                |
+-----------+-----------+---------------------------------------------+
| cr        | String    | Specifies the time when the certificate was |
| eate_time |           | created.                                    |
+-----------+-----------+---------------------------------------------+
| up        | String    | Specifies the time when the certificate was |
| date_time |           | updated.                                    |
+-----------+-----------+---------------------------------------------+

-  Example response

| {
| "name":*"cert-bky",*
| "description":*"certificate",*
| "certificate":*"*-----BEGIN
  CERTIFICATE-----\nMIIDXTCCAkWgAwIBAgIJANoPUy2NktS6MA0GCSqGSIb3DQEBBQUAMEUxCzAJBgNV\nBAYTAkFVMRMwEQYDVQQIDApTb21lLVN0YXRlMSEwHwYDVQQKDBhJbnRlcm5ldCBX\naWRnaXRzIFB0eSBMdGQwHhcNMTYwNjIyMDMyOTU5WhcNMTkwNjIyMDMyOTU5WjBF\nMQswCQYDVQQGEwJBVTETMBEGA1UECAwKU29tZS1TdGF0ZTEhMB8GA1UECgwYSW50\nZXJuZXQgV2lkZ2l0cyBQdHkgTHRkMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\nCgKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP64DjDPny9\n+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQhIOIaP1Y\nNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcsS5v3kw88\n9gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39cHX/NpIHC\nHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTams0ThvSlZ\no6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABo1AwTjAdBgNVHQ4EFgQUlXhcABza\n2SdXPYpp8RkWvKblCNIwHwYDVR0jBBgwFoAUlXhcABza2SdXPYpp8RkWvKblCNIw\nDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQUFAAOCAQEAHmsFDOwbkD45PF4oYdX+\ncCoEGNjsLfi0spJ6b1CHQMEy2tPqYZJh8nGuUtB9Zd7+rbwm6NS38eGQVA5vbWZH\nMk+uq5un7YFwkM+fdjgCxbe/3PMkk/ZDYPHhpc1W8e/+aZVUBB2EpfzBC6tcP/DV\nSsjq+tG+JZIVADMxvEqVIF94JMpuY7o6U74SnUUrAi0h9GkWmeYh/Ucb3PLMe5sF\noZriRdAKc96KB0eUphfWZNtptOCqV6qtYqZZ/UCotp99xzrDkf8jGkm/iBljxb+v\n0NTg8JwfmykCj63YhTKpHf0+N/EK5yX1KUYtlkLaf8OPlsp/1lqAL6CdnydGEd/s\nAA==\n-----END
  CERTIFICATE-----*",*
| "private_key":*"*-----BEGIN RSA PRIVATE
  KEY-----\nMIIEpAIBAAKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP6\n4DjDPny9+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQ\nhIOIaP1YNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcs\nS5v3kw889gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39c\nHX/NpIHCHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTam\ns0ThvSlZo6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABAoIBACV47rpHuxEza24O\nevbbFI9OQIcs8xA26dN1j/+HpAkzinB4o5V+XOWWZDQwbYu58hYE4NYjqf6AxHk3\nOCqAA9yKH2NXhSEyLkP7/rKDF7geZg/YtwNiR/NXTJbNXl4p8VTaVvAq3yey188x\nJCMrd1yWSsOWD2Qw7iaIBpqQIzdEovPE4CG6GmaIRSuqYuoCfbVTFa6YST7jmOTv\nEpG+x6yJZzJ4o0vvfKbKfvPmQizjL+3nAW9g+kgXJmA1xTujiky7bzm2sLK2Slrx\n5rY73mXMElseSlhkYzWwyRmC6M+rWALXqOhVDgIGbaBV4IOzuyH/CUt0wy3ZMIpv\nMOWMNoECgYEA1LHsepCmwjlDF3yf/OztCr/DYqM4HjAY6FTmH+xz1Zjd5R1XOq60\nYFRkhs/e2D6M/gSX6hMqS9sCkg25yRJk3CsPeoS9v5MoiZQA8XlQNovcpWUI2DCm\naZRIsdovFgIqMHYh/Y4CYouee7Nz7foICzO9svrYrbOIVmMwDVJ8vzMCgYEA0ebg\nm0lCuOunyxaSBqOv4Q4sk7Ix0702dIrW0tsUJyU+xuXYH1P/0m+t4/KUU2cNwsg3\njiNzQR9QKvF8yTB5TB4Ye/9dKlu+BEOskvCpuErxc6iVJ+TZOrQDDPNcq56qez5b\nvv9EDdgzpjkjO+hS1j3kYOuG11hrP4Pox4PijqECgYEAz6RTZORKqFoWsZss5VK3\np0LGkEkfw/jYmBgqAQhpnSD7n20hd1yPI2vAKAxPVXTbWDFLzWygYiWRQNy9fxrB\n9F7lYYqtY5VagdVHhnYUZOvtoFoeZFA6ZeAph9elGCtM3Lq3PD2i/mmncsQibTUn\nHSiKDWzuk8UtWIjEpHze5BkCgYEAifD9eG+bzqTnn1qU2pIl2nQTLXj0r97v84Tu\niqF4zAT5DYMtFeGBBI1qLJxVh7342CH2CI4ZhxmJ+L68sAcQH8rDcnGui1DBPlIv\nDl3kW3280bJfW1lUvPRh8NfZ9dsO1HF1n75nveVwg/OWyR7zmWIRPPRrqAeua45H\nox5z/CECgYBqwlEBjue8oOkVVu/lKi6fo6jr+0u25K9dp9azHYwE0KNHX0MwRALw\nWbPgcjge23sfhbeqVvHo0JYBdRsk/OBuW73/9Sb5E+6auDoubCjC0cAIvs23MPju\nsMvKak4mQkI19foRXBydB/DDkK26iei/l0xoygrw50v2HErsQ7JcHw==\n-----END
  RSA PRIVATE KEY-----*",*
| "tenant_id":*"ed9edbc66b8b47c09f5d2fcd89430b33",*
| "id":*"5b8f908b5495452aa13beede0afc5d99",*
| "create_time":*"2016-06-27 08:14:42",*
| "update_time":*"2016-06-27 08:14:42"*
| }

#. Status Code

-  Normal

200

-  Error

+------+------------------------------+--------------------------------+
| St   | Message                      | Description                    |
| atus |                              |                                |
| Code |                              |                                |
+======+==============================+================================+
| 400  | badRequest                   | Request error.                 |
+------+------------------------------+--------------------------------+
| 401  | unauthorized                 | Authentication failed.         |
+------+------------------------------+--------------------------------+
| 403  | userDisabled                 | You do not have the permission |
|      |                              | to perform the operation.      |
+------+------------------------------+--------------------------------+
| 404  | Not Found                    | The requested page does not    |
|      |                              | exist.                         |
+------+------------------------------+--------------------------------+
| 500  | authFault                    | System error.                  |
+------+------------------------------+--------------------------------+
| 503  | serviceUnavailable           | The service is unavailable.    |
+------+------------------------------+--------------------------------+

Deleting a Certificate
~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to delete a certificate.

2. URI

DELETE /v1.0/{project_id}/elbaas/certificate/{certificate_id}

1. Parameter description

+---------+----------+---------+--------------------------------------+
| Pa      | M        | Type    | Description                          |
| rameter | andatory |         |                                      |
+=========+==========+=========+======================================+
| pro     | Yes      | String  | Specifies the project ID.            |
| ject_id |          |         |                                      |
+---------+----------+---------+--------------------------------------+
| certifi | Yes      | String  | Specifies the certificate ID.        |
| cate_id |          |         |                                      |
+---------+----------+---------+--------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

None

-  Example response

None

#. Status Code

-  Normal

204

-  Error

+------+------------------------------+--------------------------------+
| St   | Message                      | Description                    |
| atus |                              |                                |
| Code |                              |                                |
+======+==============================+================================+
| 400  | badRequest                   | Request error.                 |
+------+------------------------------+--------------------------------+
| 401  | unauthorized                 | Authentication failed.         |
+------+------------------------------+--------------------------------+
| 403  | userDisabled                 | You do not have the permission |
|      |                              | to perform the operation.      |
+------+------------------------------+--------------------------------+
| 404  | Not Found                    | The requested page does not    |
|      |                              | exist.                         |
+------+------------------------------+--------------------------------+
| 500  | authFault                    | System error.                  |
+------+------------------------------+--------------------------------+
| 503  | serviceUnavailable           | The service is unavailable.    |
+------+------------------------------+--------------------------------+

Modifying a Certificate
~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to modify the name and description of a certificate.

2. URI

PUT /v1.0/{project_id}/elbaas/certificate/{certificate_id}

1. Parameter description

+---------+--------+-------+------------------------------------------+
| Pa      | Man    | Type  | Description                              |
| rameter | datory |       |                                          |
+=========+========+=======+==========================================+
| pro     | Yes    | S     | Specifies the project ID.                |
| ject_id |        | tring |                                          |
+---------+--------+-------+------------------------------------------+
| certifi | Yes    | S     | Specifies the certificate ID.            |
| cate_id |        | tring |                                          |
+---------+--------+-------+------------------------------------------+
| name    | No     | S     | -  Specifies the certificate name.       |
|         |        | tring |                                          |
|         |        |       | -  The value can contain 0 to 64         |
|         |        |       |    characters that consist of letters,   |
|         |        |       |    digits, underscores (_), and hyphens  |
|         |        |       |    (-).                                  |
+---------+--------+-------+------------------------------------------+
| desc    | No     | S     | -  Provides supplementary information    |
| ription |        | tring |    about the certificate.                |
|         |        |       |                                          |
|         |        |       | -  The value contains a maximum of 128   |
|         |        |       |    characters and cannot contain angle   |
|         |        |       |    brackets (< and >).                   |
+---------+--------+-------+------------------------------------------+

#. Request

-  Request parameters

None

-  Example request

| {
| "name": "cert-bky",
| "description": "certificate"
| }

#. Response

-  Response parameters

   1. Parameter description

+-----------+--------+------------------------------------------------+
| Parameter | Type   | Description                                    |
+===========+========+================================================+
| id        | String | Specifies the certificate ID.                  |
+-----------+--------+------------------------------------------------+
| name      | String | Specifies the certificate name.                |
+-----------+--------+------------------------------------------------+
| de        | String | Provides supplementary information about the   |
| scription |        | certificate.                                   |
+-----------+--------+------------------------------------------------+
| domain    | String | Specifies the domain name associated with the  |
|           |        | server certificate.                            |
+-----------+--------+------------------------------------------------+
| ce        | String | Specifies the certificate content.             |
| rtificate |        |                                                |
+-----------+--------+------------------------------------------------+
| pr        | String | Specifies the private key of the certificate.  |
| ivate_key |        |                                                |
+-----------+--------+------------------------------------------------+
| cr        | String | Specifies the time when the certificate was    |
| eate_time |        | created.                                       |
+-----------+--------+------------------------------------------------+
| up        | String | Specifies the time when the certificate was    |
| date_time |        | updated.                                       |
+-----------+--------+------------------------------------------------+

-  Example response

| {
| "name": "cert-bky",
| "description": "certificate",
| "domain": null,
| "certificate": "-----BEGIN
  CERTIFICATE-----\nMIIDXTCCAkWgAwIBAgIJANoPUy2NktS6MA0GCSqGSIb3DQEBBQUAMEUxCzAJBgNV\nBAYTAkFVMRMwEQYDVQQIDApTb21lLVN0YXRlMSEwHwYDVQQKDBhJbnRlcm5ldCBX\naWRnaXRzIFB0eSBMdGQwHhcNMTYwNjIyMDMyOTU5WhcNMTkwNjIyMDMyOTU5WjBF\nMQswCQYDVQQGEwJBVTETMBEGA1UECAwKU29tZS1TdGF0ZTEhMB8GA1UECgwYSW50\nZXJuZXQgV2lkZ2l0cyBQdHkgTHRkMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\nCgKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP64DjDPny9\n+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQhIOIaP1Y\nNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcsS5v3kw88\n9gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39cHX/NpIHC\nHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTams0ThvSlZ\no6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABo1AwTjAdBgNVHQ4EFgQUlXhcABza\n2SdXPYpp8RkWvKblCNIwHwYDVR0jBBgwFoAUlXhcABza2SdXPYpp8RkWvKblCNIw\nDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQUFAAOCAQEAHmsFDOwbkD45PF4oYdX+\ncCoEGNjsLfi0spJ6b1CHQMEy2tPqYZJh8nGuUtB9Zd7+rbwm6NS38eGQVA5vbWZH\nMk+uq5un7YFwkM+fdjgCxbe/3PMkk/ZDYPHhpc1W8e/+aZVUBB2EpfzBC6tcP/DV\nSsjq+tG+JZIVADMxvEqVIF94JMpuY7o6U74SnUUrAi0h9GkWmeYh/Ucb3PLMe5sF\noZriRdAKc96KB0eUphfWZNtptOCqV6qtYqZZ/UCotp99xzrDkf8jGkm/iBljxb+v\n0NTg8JwfmykCj63YhTKpHf0+N/EK5yX1KUYtlkLaf8OPlsp/1lqAL6CdnydGEd/s\nAA==\n-----END
  CERTIFICATE-----",
| "private_key": "-----BEGIN RSA PRIVATE
  KEY-----\nMIIEpAIBAAKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP6\n4DjDPny9+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQ\nhIOIaP1YNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcs\nS5v3kw889gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39c\nHX/NpIHCHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTam\ns0ThvSlZo6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABAoIBACV47rpHuxEza24O\nevbbFI9OQIcs8xA26dN1j/+HpAkzinB4o5V+XOWWZDQwbYu58hYE4NYjqf6AxHk3\nOCqAA9yKH2NXhSEyLkP7/rKDF7geZg/YtwNiR/NXTJbNXl4p8VTaVvAq3yey188x\nJCMrd1yWSsOWD2Qw7iaIBpqQIzdEovPE4CG6GmaIRSuqYuoCfbVTFa6YST7jmOTv\nEpG+x6yJZzJ4o0vvfKbKfvPmQizjL+3nAW9g+kgXJmA1xTujiky7bzm2sLK2Slrx\n5rY73mXMElseSlhkYzWwyRmC6M+rWALXqOhVDgIGbaBV4IOzuyH/CUt0wy3ZMIpv\nMOWMNoECgYEA1LHsepCmwjlDF3yf/OztCr/DYqM4HjAY6FTmH+xz1Zjd5R1XOq60\nYFRkhs/e2D6M/gSX6hMqS9sCkg25yRJk3CsPeoS9v5MoiZQA8XlQNovcpWUI2DCm\naZRIsdovFgIqMHYh/Y4CYouee7Nz7foICzO9svrYrbOIVmMwDVJ8vzMCgYEA0ebg\nm0lCuOunyxaSBqOv4Q4sk7Ix0702dIrW0tsUJyU+xuXYH1P/0m+t4/KUU2cNwsg3\njiNzQR9QKvF8yTB5TB4Ye/9dKlu+BEOskvCpuErxc6iVJ+TZOrQDDPNcq56qez5b\nvv9EDdgzpjkjO+hS1j3kYOuG11hrP4Pox4PijqECgYEAz6RTZORKqFoWsZss5VK3\np0LGkEkfw/jYmBgqAQhpnSD7n20hd1yPI2vAKAxPVXTbWDFLzWygYiWRQNy9fxrB\n9F7lYYqtY5VagdVHhnYUZOvtoFoeZFA6ZeAph9elGCtM3Lq3PD2i/mmncsQibTUn\nHSiKDWzuk8UtWIjEpHze5BkCgYEAifD9eG+bzqTnn1qU2pIl2nQTLXj0r97v84Tu\niqF4zAT5DYMtFeGBBI1qLJxVh7342CH2CI4ZhxmJ+L68sAcQH8rDcnGui1DBPlIv\nDl3kW3280bJfW1lUvPRh8NfZ9dsO1HF1n75nveVwg/OWyR7zmWIRPPRrqAeua45H\nox5z/CECgYBqwlEBjue8oOkVVu/lKi6fo6jr+0u25K9dp9azHYwE0KNHX0MwRALw\nWbPgcjge23sfhbeqVvHo0JYBdRsk/OBuW73/9Sb5E+6auDoubCjC0cAIvs23MPju\nsMvKak4mQkI19foRXBydB/DDkK26iei/l0xoygrw50v2HErsQ7JcHw==\n-----END
  RSA PRIVATE KEY-----",
| "id": "5b8f908b5495452aa13beede0afc5d99",
| "create_time": "2016-06-27 08:14:42",
| "update_time": "2016-06-27 08:14:42"
| }

#. Status Code

-  Normal

200

-  Error

+-----+-------------------------------+--------------------------------+
| Sta | Message                       | Description                    |
| tus |                               |                                |
| C   |                               |                                |
| ode |                               |                                |
+=====+===============================+================================+
| 400 | badRequest                    | Request error.                 |
+-----+-------------------------------+--------------------------------+
| 401 | unauthorized                  | Authentication failed.         |
+-----+-------------------------------+--------------------------------+
| 403 | userDisabled                  | You do not have the permission |
|     |                               | to perform the operation.      |
+-----+-------------------------------+--------------------------------+
| 404 | Not Found                     | The requested page does not    |
|     |                               | exist.                         |
+-----+-------------------------------+--------------------------------+
| 500 | authFault                     | System error.                  |
+-----+-------------------------------+--------------------------------+
| 503 | serviceUnavailable            | The service is unavailable.    |
+-----+-------------------------------+--------------------------------+

Querying Certificates
~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query all the certificates.

2. URI

GET /v1.0/{project_id}/elbaas/certificate

1. Parameter description

+----------+---------+------+----------------------------------------+
| P        | Ma      | Type | Description                            |
| arameter | ndatory |      |                                        |
+==========+=========+======+========================================+
| pr       | Yes     | St   | Specifies the project ID.              |
| oject_id |         | ring |                                        |
+----------+---------+------+----------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Response parameters

+----------+---------+------------------------------------------------+
| P        | Type    | Description                                    |
| arameter |         |                                                |
+==========+=========+================================================+
| cert     | Array   | Lists the certificates.                        |
| ificates |         |                                                |
+----------+---------+------------------------------------------------+
| inst     | String  | Specifies the number of certificates.          |
| ance_num |         |                                                |
+----------+---------+------------------------------------------------+

2. **certificates** parameter description

+----------+---------+------------------------------------------------+
| P        | Type    | Description                                    |
| arameter |         |                                                |
+==========+=========+================================================+
| id       | String  | Specifies the certificate ID.                  |
+----------+---------+------------------------------------------------+
| name     | String  | Specifies the certificate name.                |
+----------+---------+------------------------------------------------+
| des      | String  | Provides supplementary information about the   |
| cription |         | certificate.                                   |
+----------+---------+------------------------------------------------+
| domain   | String  | Specifies the domain name associated with the  |
|          |         | server certificate.                            |
+----------+---------+------------------------------------------------+
| cer      | String  | Specifies the certificate content.             |
| tificate |         |                                                |
+----------+---------+------------------------------------------------+
| pri      | String  | Specifies the private key of the certificate.  |
| vate_key |         |                                                |
+----------+---------+------------------------------------------------+
| cre      | String  | Specifies the time when the certificate was    |
| ate_time |         | created.                                       |
+----------+---------+------------------------------------------------+
| upd      | String  | Specifies the time when the certificate was    |
| ate_time |         | updated.                                       |
+----------+---------+------------------------------------------------+

-  Example response

| {
| "certificates": [
| {
| "name": "cert-bky",
| "description": "certificate",
| "domain": null,
| "certificate": "-----BEGIN
  CERTIFICATE-----\nMIIDXTCCAkWgAwIBAgIJANoPUy2NktS6MA0GCSqGSIb3DQEBBQUAMEUxCzAJBgNV\nBAYTAkFVMRMwEQYDVQQIDApTb21lLVN0YXRlMSEwHwYDVQQKDBhJbnRlcm5ldCBX\naWRnaXRzIFB0eSBMdGQwHhcNMTYwNjIyMDMyOTU5WhcNMTkwNjIyMDMyOTU5WjBF\nMQswCQYDVQQGEwJBVTETMBEGA1UECAwKU29tZS1TdGF0ZTEhMB8GA1UECgwYSW50\nZXJuZXQgV2lkZ2l0cyBQdHkgTHRkMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIB\nCgKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP64DjDPny9\n+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQhIOIaP1Y\nNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcsS5v3kw88\n9gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39cHX/NpIHC\nHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTams0ThvSlZ\no6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABo1AwTjAdBgNVHQ4EFgQUlXhcABza\n2SdXPYpp8RkWvKblCNIwHwYDVR0jBBgwFoAUlXhcABza2SdXPYpp8RkWvKblCNIw\nDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQUFAAOCAQEAHmsFDOwbkD45PF4oYdX+\ncCoEGNjsLfi0spJ6b1CHQMEy2tPqYZJh8nGuUtB9Zd7+rbwm6NS38eGQVA5vbWZH\nMk+uq5un7YFwkM+fdjgCxbe/3PMkk/ZDYPHhpc1W8e/+aZVUBB2EpfzBC6tcP/DV\nSsjq+tG+JZIVADMxvEqVIF94JMpuY7o6U74SnUUrAi0h9GkWmeYh/Ucb3PLMe5sF\noZriRdAKc96KB0eUphfWZNtptOCqV6qtYqZZ/UCotp99xzrDkf8jGkm/iBljxb+v\n0NTg8JwfmykCj63YhTKpHf0+N/EK5yX1KUYtlkLaf8OPlsp/1lqAL6CdnydGEd/s\nAA==\n-----END
  CERTIFICATE-----",
| "private_key": "-----BEGIN RSA PRIVATE
  KEY-----\nMIIEpAIBAAKCAQEArmUUhzm5sxxVr/ku4+6cKqnKgZvDl+e/6CNCAq8YMZXTpJP6\n4DjDPny9+8s9MbFabEG3HqjHSKh3b/Ew3FXr8LFa9YuWuAi3W9ii29sZsOwmzIfQ\nhIOIaP1YNR50DDjbAGTaxzRhV40ZKSOCkaUTvl3do5d8ttD1VlF2r0w0DfclrVcs\nS5v3kw889gJ3s3hNkatfQiSt4qLNMehZ8Xofx58DIAOk/f3Vusj3372PsJwKX39c\nHX/NpIHCHKE8qaGCpDqv0daH766eJ065dqO9DuorXPaPT/nxw4PAccb9fByLrTam\ns0ThvSlZo6V3yvHR4KN7mmvbViEmWRy+9oiJEwIDAQABAoIBACV47rpHuxEza24O\nevbbFI9OQIcs8xA26dN1j/+HpAkzinB4o5V+XOWWZDQwbYu58hYE4NYjqf6AxHk3\nOCqAA9yKH2NXhSEyLkP7/rKDF7geZg/YtwNiR/NXTJbNXl4p8VTaVvAq3yey188x\nJCMrd1yWSsOWD2Qw7iaIBpqQIzdEovPE4CG6GmaIRSuqYuoCfbVTFa6YST7jmOTv\nEpG+x6yJZzJ4o0vvfKbKfvPmQizjL+3nAW9g+kgXJmA1xTujiky7bzm2sLK2Slrx\n5rY73mXMElseSlhkYzWwyRmC6M+rWALXqOhVDgIGbaBV4IOzuyH/CUt0wy3ZMIpv\nMOWMNoECgYEA1LHsepCmwjlDF3yf/OztCr/DYqM4HjAY6FTmH+xz1Zjd5R1XOq60\nYFRkhs/e2D6M/gSX6hMqS9sCkg25yRJk3CsPeoS9v5MoiZQA8XlQNovcpWUI2DCm\naZRIsdovFgIqMHYh/Y4CYouee7Nz7foICzO9svrYrbOIVmMwDVJ8vzMCgYEA0ebg\nm0lCuOunyxaSBqOv4Q4sk7Ix0702dIrW0tsUJyU+xuXYH1P/0m+t4/KUU2cNwsg3\njiNzQR9QKvF8yTB5TB4Ye/9dKlu+BEOskvCpuErxc6iVJ+TZOrQDDPNcq56qez5b\nvv9EDdgzpjkjO+hS1j3kYOuG11hrP4Pox4PijqECgYEAz6RTZORKqFoWsZss5VK3\np0LGkEkfw/jYmBgqAQhpnSD7n20hd1yPI2vAKAxPVXTbWDFLzWygYiWRQNy9fxrB\n9F7lYYqtY5VagdVHhnYUZOvtoFoeZFA6ZeAph9elGCtM3Lq3PD2i/mmncsQibTUn\nHSiKDWzuk8UtWIjEpHze5BkCgYEAifD9eG+bzqTnn1qU2pIl2nQTLXj0r97v84Tu\niqF4zAT5DYMtFeGBBI1qLJxVh7342CH2CI4ZhxmJ+L68sAcQH8rDcnGui1DBPlIv\nDl3kW3280bJfW1lUvPRh8NfZ9dsO1HF1n75nveVwg/OWyR7zmWIRPPRrqAeua45H\nox5z/CECgYBqwlEBjue8oOkVVu/lKi6fo6jr+0u25K9dp9azHYwE0KNHX0MwRALw\nWbPgcjge23sfhbeqVvHo0JYBdRsk/OBuW73/9Sb5E+6auDoubCjC0cAIvs23MPju\nsMvKak4mQkI19foRXBydB/DDkK26iei/l0xoygrw50v2HErsQ7JcHw==\n-----END
  RSA PRIVATE KEY-----",
| "id": "5b8f908b5495452aa13beede0afc5d99",
| "create_time": "2016-06-27 08:14:42",
| "update_time": "2016-06-27 08:14:42"
| }
| ],
| "instance_num": "1"
| }

#. Status Code

-  Normal

200

-  Error

+------+-----------------------------+--------------------------------+
| St   | Message                     | Description                    |
| atus |                             |                                |
| Code |                             |                                |
+======+=============================+================================+
| 400  | badRequest                  | Request error.                 |
+------+-----------------------------+--------------------------------+
| 401  | unauthorized                | Authentication failed.         |
+------+-----------------------------+--------------------------------+
| 403  | userDisabled                | You do not have the permission |
|      |                             | to perform the operation.      |
+------+-----------------------------+--------------------------------+
| 404  | Not Found                   | The requested page does not    |
|      |                             | exist.                         |
+------+-----------------------------+--------------------------------+
| 500  | authFault                   | System error.                  |
+------+-----------------------------+--------------------------------+
| 503  | serviceUnavailable          | The service is unavailable.    |
+------+-----------------------------+--------------------------------+

Querying the Job Status
-----------------------

#. Function

This API is used to query the job status, such as the execution status
of creating or deleting a load balancer.

2. URI

GET /v1.0/{project_id}/jobs/{job_id}

1. Parameter description

+--------+---------+---------+----------------------------------------+
| Par    | Ma      | Type    | Description                            |
| ameter | ndatory |         |                                        |
+========+=========+=========+========================================+
| proj   | Yes     | String  | Specifies the project ID.              |
| ect_id |         |         |                                        |
+--------+---------+---------+----------------------------------------+
| job_id | Yes     | String  | Specifies the job ID.                  |
+--------+---------+---------+----------------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+--------------+---------+-----+---------------------------------------+
| Parameter    | Ma      | T   | Description                           |
|              | ndatory | ype |                                       |
+==============+=========+=====+=======================================+
| status       | Yes     | Str | Specifies the job status.             |
|              |         | ing |                                       |
|              |         |     | -  **SUCCESS**: The job was           |
|              |         |     |    successfully executed.             |
|              |         |     |                                       |
|              |         |     | -  **RUNNING**: The job is in         |
|              |         |     |    progress.                          |
|              |         |     |                                       |
|              |         |     | -  **FAIL**: The job failed.          |
|              |         |     |                                       |
|              |         |     | -  **INIT**: The job is being         |
|              |         |     |    initialized.                       |
+--------------+---------+-----+---------------------------------------+
| entities     | Yes     | Obj | Specifies the response to the job.    |
|              |         | ect | Each type of job has different        |
|              |         |     | contents.                             |
+--------------+---------+-----+---------------------------------------+
| job_id       | Yes     | Str | Specifies the job ID.                 |
|              |         | ing |                                       |
+--------------+---------+-----+---------------------------------------+
| job_type     | Yes     | Str | Specifies the job type.               |
|              |         | ing |                                       |
+--------------+---------+-----+---------------------------------------+
| begin_time   | Yes     | Str | Specifies the time when the job       |
|              |         | ing | started.                              |
+--------------+---------+-----+---------------------------------------+
| end_time     | Yes     | Str | Specifies the time when the job       |
|              |         | ing | ended.                                |
+--------------+---------+-----+---------------------------------------+
| error_code   | Yes     | Str | Specifies the error code returned     |
|              |         | ing | after the job fails to execute.       |
+--------------+---------+-----+---------------------------------------+
| fail_reason  | Yes     | Str | Indicates the cause of the execution  |
|              |         | ing | failure.                              |
+--------------+---------+-----+---------------------------------------+
| message      | No      | Str | Specifies the message returned when   |
|              |         | ing | an error occurs.                      |
+--------------+---------+-----+---------------------------------------+
| code         | No      | Str | Specifies the error code returned     |
|              |         | ing | when an error occurs.                 |
|              |         |     |                                       |
|              |         |     | For details of error code, see `Error |
|              |         |     | Codes <#error-codes>`__.              |
+--------------+---------+-----+---------------------------------------+
| sub_jobs     | No      | Str | Specifies the execution information   |
|              |         | ing | of a subjob. When no subjob exists,   |
|              |         |     | the value of this parameter is left   |
|              |         |     | empty. The structure of each subjob   |
|              |         |     | is similar to that of the parent job. |
+--------------+---------+-----+---------------------------------------+

-  Example response

| {
| "status": "SUCCESS",
| "entities":
| {
| "elb":
| {
| "id": "ef265755daf84333baf4ddc1d91cbc2f",
| "name": "1",
| "type": "External",
| "status": "ACTIVE",
| "bandwidth": 1,
| "vip_address": "10.154.53.4",
| "tenant_id": "cbc08e2f8c354c7aa7abb88d0a7d11dc",
| "admin_state_up": false,
| "vpc_id": "21838be1-c1ce-4c09-9184-228cdb43038d"
| }
| },
| "job_id": "ff8080825ecc523f015ecd0a98f82f77",
| "job_type": "createELB",
| "begin_time": "2017-09-29T09:49:37.399Z",
| "end_time": "2017-09-29T09:50:03.272Z",
| "error_code": null,
| "fail_reason": null
| }

#. Status Code

-  Normal

200

-  Error

+-------+-----------------------+--------------------------------------+
| S     | Message               | Description                          |
| tatus |                       |                                      |
| Code  |                       |                                      |
+=======+=======================+======================================+
| 400   | Bad Request           | The server failed to process the     |
|       |                       | request.                             |
+-------+-----------------------+--------------------------------------+
| 401   | Unauthorized          | You must enter a username and the    |
|       |                       | password to access the requested     |
|       |                       | page.                                |
+-------+-----------------------+--------------------------------------+
| 403   | Forbidden             | You are forbidden to access the      |
|       |                       | requested page.                      |
+-------+-----------------------+--------------------------------------+
| 404   | Not Found             | The server could not find the        |
|       |                       | requested page.                      |
+-------+-----------------------+--------------------------------------+
| 405   | Method Not Allowed    | You are not allowed to use the       |
|       |                       | method specified in the request.     |
+-------+-----------------------+--------------------------------------+
| 406   | Not Acceptable        | Response generated by the server is  |
|       |                       | not acceptable to the client.        |
+-------+-----------------------+--------------------------------------+
| 407   | Proxy Authentication  | You must use the proxy server for    |
|       | Required              | authentication so that the request   |
|       |                       | can be processed.                    |
+-------+-----------------------+--------------------------------------+
| 408   | Request Timeout       | The request timed out.               |
+-------+-----------------------+--------------------------------------+
| 409   | Conflict              | The request could not be processed   |
|       |                       | due to a conflict.                   |
+-------+-----------------------+--------------------------------------+
| 500   | Internal Server Error | Failed to complete the request       |
|       |                       | because of an internal service       |
|       |                       | error.                               |
+-------+-----------------------+--------------------------------------+
| 501   | Not Implemented       | Failed to complete the request       |
|       |                       | because the server does not support  |
|       |                       | the requested function.              |
+-------+-----------------------+--------------------------------------+
| 502   | Bad Gateway           | Failed to complete the request       |
|       |                       | because the server has received an   |
|       |                       | invalid response.                    |
+-------+-----------------------+--------------------------------------+
| 503   | Service Unavailable   | Failed to complete the request       |
|       |                       | because the system is out of service |
|       |                       | temporarily.                         |
+-------+-----------------------+--------------------------------------+
| 504   | Gateway Timeout       | A gateway timeout error occurred.    |
+-------+-----------------------+--------------------------------------+

Querying Monitoring Metrics
---------------------------

#. Function

This API is used to query all metrics at Layer 4 and Layer 7.

Only users can query these metrics.

2. URI

GET /v1.0/{project_id}/elbaas/monitor

1. Parameter description

+------------+-----------+------------+------------------------------+
| Parameter  | Mandatory | Type       | Description                  |
+============+===========+============+==============================+
| project_id | Yes       | String     | Specifies the project ID.    |
+------------+-----------+------------+------------------------------+

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Response parameters

+-----------------------+-----------------------+-----------------------+
| Parameter             | Type                  | Description           |
+=======================+=======================+=======================+
| act_conn              | Integer               | Specifies the number  |
|                       |                       | of active             |
|                       |                       | connections.          |
+-----------------------+-----------------------+-----------------------+
| cps                   | Integer               | Specifies the number  |
|                       |                       | of concurrent         |
|                       |                       | connections.          |
+-----------------------+-----------------------+-----------------------+
| create_time           | String                | Specifies the report  |
|                       |                       | time.                 |
+-----------------------+-----------------------+-----------------------+
| in_Bps                | Integer               | Specifies the inbound |
|                       |                       | rate (bytes/s).       |
+-----------------------+-----------------------+-----------------------+
| in_pps                | Integer               | Specifies the number  |
|                       |                       | of incoming data      |
|                       |                       | packets.              |
+-----------------------+-----------------------+-----------------------+
| inact_conn            | Integer               | Specifies the number  |
|                       |                       | of inactive           |
|                       |                       | connections.          |
+-----------------------+-----------------------+-----------------------+
| loadbalancer_id       | String                | Specifies the load    |
|                       |                       | balancer ID.          |
+-----------------------+-----------------------+-----------------------+
| loadbalancer_ip       | String                | Specifies the load    |
|                       |                       | balancer IP address.  |
+-----------------------+-----------------------+-----------------------+
| loadbalancer_name     | String                | Specifies the load    |
|                       |                       | balancer name.        |
+-----------------------+-----------------------+-----------------------+
| ncps                  | Integer               | Specifies the number  |
|                       |                       | of new connections.   |
+-----------------------+-----------------------+-----------------------+
| out_Bps               | Integer               | Specifies the         |
|                       |                       | outbound rate         |
|                       |                       | (bytes/s).            |
+-----------------------+-----------------------+-----------------------+
| out_pps               | Integer               | Specifies the number  |
|                       |                       | of outgoing data      |
|                       |                       | packets.              |
+-----------------------+-----------------------+-----------------------+

-  Example response

| [
| {
| "act_conn": 0,
| "cps": 0,
| "create_time": "2016-05-20 16:46:49",
| "in_Bps": 0,
| "in_pps": 0,
| "inact_conn": 0,
| "loadbalancer_id": "34cf6520808d4766ae1455586ab94ba8",
| "loadbalancer_ip": "10.10.1.233",
| "loadbalancer_name": "lb0721",
| "ncps": 0,
| "out_Bps": 0,
| "out_pps": 0
| },
| {
| "act_conn": 0,
| "cps": 0,
| "create_time": "2016-05-20 16:46:49",
| "in_Bps": 0,
| "in_pps": 0,
| "inact_conn": 0,
| "loadbalancer_id": "b44533cce271437bb692365b0c450543",
| "loadbalancer_ip": "10.10.1.253",
| "loadbalancer_name": "lb0721",
| "ncps": 0,
| "out_Bps": 0,
| "out_pps": 0
| }
| ]

API Version
-----------

1. .. rubric:: Querying All API Versions
      :name: querying-all-api-versions

   #. Function

This API is used to query all API versions of ELB.

2. URI

GET /

3. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Parameter description

+-------------+--------+-------------------------------------------------+
| Pa          | Type   | Description                                     |
| rameter     |        |                                                 |
+=============+========+=================================================+
| v           | Array  | Lists all API versions.                         |
| ersions     |        |                                                 |
+-------------+--------+-------------------------------------------------+
| id          | String | Specifies the version ID, for example, **v1**.  |
+-------------+--------+-------------------------------------------------+
| links       | Array  | Specifies the API URL.                          |
+-------------+--------+-------------------------------------------------+
| href        | String | Specifies the reference address of the current  |
|             |        | API version.                                    |
+-------------+--------+-------------------------------------------------+
| rel         | String | Specifies the relationship between the current  |
|             |        | API version and the referenced address.         |
+-------------+--------+-------------------------------------------------+
| version     | String | Specifies the version. If minor versions are    |
|             |        | supported, set this parameter to the latest     |
|             |        | minor version. If minor versions are not        |
|             |        | supported, leave this parameter blank.          |
+-------------+--------+-------------------------------------------------+
| status      | String | Specifies the version status. Options are as    |
|             |        | follows:                                        |
|             |        |                                                 |
|             |        | -  **CURRENT**: indicates the major version.    |
|             |        |                                                 |
|             |        | -  **SUPPORTED**: indicates that the version is |
|             |        |    an old one, but it is still supported.       |
|             |        |                                                 |
|             |        | -  **DEPRECATED**: indicates a deprecated       |
|             |        |    version which may be deleted later.          |
+-------------+--------+-------------------------------------------------+
| updated     | String | Specifies the version release time, which must  |
|             |        | be the UTC time. For example, the release time  |
|             |        | of v1 is 2014-06-28T12:20:21Z.                  |
+-------------+--------+-------------------------------------------------+
| min_version | String | Specifies the minor version. If minor versions  |
|             |        | are supported, set this parameter to the        |
|             |        | earliest minor version. If minor versions are   |
|             |        | not supported, leave this parameter blank.      |
+-------------+--------+-------------------------------------------------+

-  Example response

| {
| "versions": [
| {
| "id": "v1.0",
| "links": [
| {
| "href": "https://{elb_endpoint}/v1.0/",
| "rel": "self"
| }
| ],
| "min_version": "",
| "status": "CURRENT",
| "updated": "2018-09-30T00:00:00Z",
| "version": ""
| }
| ]
| }

#. Status Code

-  Normal

200

-  Error

+-------+------------------------------------+------------------------+
| S     | Message                            | Description            |
| tatus |                                    |                        |
| Code  |                                    |                        |
+=======+====================================+========================+
| 400   | Bad Request                        | Request error.         |
+-------+------------------------------------+------------------------+
| 401   | Unauthorized                       | The authentication     |
|       |                                    | information is not     |
|       |                                    | provided or is         |
|       |                                    | incorrect.             |
+-------+------------------------------------+------------------------+
| 403   | Forbidden                          | The request was        |
|       |                                    | forbidden.             |
+-------+------------------------------------+------------------------+
| 404   | Not Found                          | The requested resource |
|       |                                    | does not exist.        |
+-------+------------------------------------+------------------------+
| 408   | Request Timeout                    | The request timed out. |
+-------+------------------------------------+------------------------+
| 429   | Too Many Requests                  | The number requests    |
|       |                                    | exceeded the upper     |
|       |                                    | limit.                 |
+-------+------------------------------------+------------------------+
| 500   | Internal Server Error              | Failed to complete the |
|       |                                    | request because of an  |
|       |                                    | internal service       |
|       |                                    | error.                 |
+-------+------------------------------------+------------------------+
| 503   | Service Unavailable                | The service is         |
|       |                                    | currently unavailable. |
+-------+------------------------------------+------------------------+

Querying a Specific API Version
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#. Function

This API is used to query a specific ELB API version.

2. URI

GET /{api_version}

1. Parameter description

+----------+----------+-----------------------------------------------+
| P        | M        | Description                                   |
| arameter | andatory |                                               |
+==========+==========+===============================================+
| api      | Yes      | Specifies the API version.                    |
| _version |          |                                               |
+----------+----------+-----------------------------------------------+

-  **Example**

/v1.0

#. Request

-  Request parameters

None

-  Example request

None

#. Response

-  Response parameters

   1. Response parameters

+-------------+--------+------------------------------------------------+
| Parameter   | Type   | Description                                    |
|             |        |                                                |
+=============+========+================================================+
| version     | Object | Specifies the API version.                     |
+-------------+--------+------------------------------------------------+
| id          | String | Specifies the version ID, for example, **v1**. |
+-------------+--------+------------------------------------------------+
| links       | Array  | Specifies the API URL.                         |
+-------------+--------+------------------------------------------------+
| href        | String | Specifies the reference address of the current |
|             |        | API version.                                   |
+-------------+--------+------------------------------------------------+
| rel         | String | Specifies the relationship between the current |
|             |        | API version and the referenced address.        |
+-------------+--------+------------------------------------------------+
| version     | String | Specifies the version. If minor versions are   |
|             |        | supported, set this parameter to the latest    |
|             |        | minor version. If minor versions are not       |
|             |        | supported, leave this parameter blank.         |
+-------------+--------+------------------------------------------------+
| status      | String | Specifies the version status. Options are as   |
|             |        | follows:                                       |
|             |        |                                                |
|             |        | -  **CURRENT**: indicates the major version.   |
|             |        |                                                |
|             |        | -  **SUPPORTED**: indicates that the version   |
|             |        |    is an old one, but it is still supported.   |
|             |        |                                                |
|             |        | -  **DEPRECATED**: indicates a deprecated      |
|             |        |    version which may be deleted later.         |
+-------------+--------+------------------------------------------------+
| updated     | String | Specifies the version release time, which must |
|             |        | be the UTC time. For example, the release time |
|             |        | of v1 is 2014-06-28T12:20:21Z.                 |
+-------------+--------+------------------------------------------------+
| min_version | String | Specifies the minor version. If minor versions |
|             |        | are supported, set this parameter to the       |
|             |        | earliest minor version. If minor versions are  |
|             |        | not supported, leave this parameter blank.     |
+-------------+--------+------------------------------------------------+

-  Example response

| {
| "version": {
| "id": "v1.0",
| "links": [
| {
| "href": "https://{elb_endpoint}/v1.0/",
| "rel": "self"
| }
| ],
| "min_version": "",
| "status": "CURRENT",
| "updated": "2018-09-30T00:00:00Z",
| "version": ""
| }
| }

#. Status Code

-  Normal

200

-  Error

+------+--------------------------------------+------------------------+
| St   | Message                              | Description            |
| atus |                                      |                        |
| Code |                                      |                        |
+======+======================================+========================+
| 400  | Bad Request                          | Request error.         |
+------+--------------------------------------+------------------------+
| 401  | Unauthorized                         | The authentication     |
|      |                                      | information is not     |
|      |                                      | provided or is         |
|      |                                      | incorrect.             |
+------+--------------------------------------+------------------------+
| 403  | Forbidden                            | The request was        |
|      |                                      | forbidden.             |
+------+--------------------------------------+------------------------+
| 404  | Not Found                            | The requested resource |
|      |                                      | does not exist.        |
+------+--------------------------------------+------------------------+
| 408  | Request Timeout                      | The request timed out. |
+------+--------------------------------------+------------------------+
| 429  | Too Many Requests                    | The number requests    |
|      |                                      | exceeded the upper     |
|      |                                      | limit.                 |
+------+--------------------------------------+------------------------+
| 500  | Internal Server Error                | Failed to complete the |
|      |                                      | request because of an  |
|      |                                      | internal service       |
|      |                                      | error.                 |
+------+--------------------------------------+------------------------+
| 503  | Service Unavailable                  | The service is         |
|      |                                      | currently unavailable. |
+------+--------------------------------------+------------------------+

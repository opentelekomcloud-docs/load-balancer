.. -*- rst -*-

API Call Precaution
===================
By default, load balancers created in the eu-nl region
are dedicated load balancers. APIs for dedicated load
balancers are only available in this region. Shared load
balancers and dedicated load balancers are called elastic
load balancers collectively.

.. _insert_headers:

Supported Headers
=================

+----------------------+---------+---------------------------------------+
| Parameter            | Type    | Description                           |
+======================+=========+=======================================+
| X-Forwarded-ELB-IP   | Boolean | Specifies whether to transparently    |
|                      |         | transmit the load balancer EIP to     |
|                      |         | backend servers. If                   |
|                      |         | **X-Forwarded-ELB-IP** is set to      |
|                      |         | **true**, the load balancer EIP will  |
|                      |         | be stored in the HTTP header and      |
|                      |         | passed to backend servers.            |
|                      |         |                                       |
|                      |         | Default: **false**                    |
+----------------------+---------+---------------------------------------+
| X-Forwarded-Port     | Boolean | Specifies whether to transparently    |
|                      |         | transmit the listening port of the    |
|                      |         | load balancer to backend servers. If  |
|                      |         | **X-Forwarded-Port** is set to        |
|                      |         | **true**, the listening port of the   |
|                      |         | load balancer will be stored in the   |
|                      |         | HTTP header and passed to backend     |
|                      |         | servers.                              |
|                      |         |                                       |
|                      |         | Default: **false**                    |
+----------------------+---------+---------------------------------------+
| X-Forwarded-For-Port | Boolean | Specifies whether to transparently    |
|                      |         | transmit the source port of the       |
|                      |         | client to backend servers. If         |
|                      |         | **X-Forwarded-For-Port** is set to    |
|                      |         | **true**, the source port of the      |
|                      |         | client will be stored in the HTTP     |
|                      |         | header and passed to backend servers. |
|                      |         |                                       |
|                      |         | Default: **false**                    |
+----------------------+---------+---------------------------------------+
| X-Forwarded-Host     | Boolean | Specifies whether to rewrite the      |
|                      |         | **X-Forwarded-Host** header. If       |
|                      |         | **X-Forwarded-Host** is set to        |
|                      |         | **true**, **X-Forwarded-Host** in the |
|                      |         | request header from the clients can   |
|                      |         | be set to **Host** in the request     |
|                      |         | header sent from the load balancer to |
|                      |         | backend servers.                      |
|                      |         |                                       |
|                      |         | Default: **true**                     |
+----------------------+---------+---------------------------------------+

.. _op_status:

Operating Status Codes
======================

+------------+------------------------------------------------------------+
| Code       | Description                                                |
+============+============================================================+
| ONLINE     | - Entity is operating normally                             |
|            | - All pool members are healthy                             |
+------------+------------------------------------------------------------+
| DRAINING   | - The member is not accepting new connections              |
+------------+------------------------------------------------------------+
| OFFLINE    | - Entity is administratively disabled                      |
+------------+------------------------------------------------------------+
| DEGRADED   | - One or more of the entity's components are in ERROR      |
+------------+------------------------------------------------------------+
| ERROR      | - The entity has failed                                    |
|            | - The member is failing it's health monitoring checks      |
|            | - All of the pool members are in ERROR                     |
+------------+------------------------------------------------------------+
| NO_MONITOR | - No health monitor is configured for this entity and it's |
|            |   status is unknown                                        |
+------------+------------------------------------------------------------+
| DISABLED   | This status is displayed only when admin_state_up of the   |
|            | resource is set to false.                                  |
+------------+------------------------------------------------------------+

.. _dsc:

HTTP Status Codes
=================

The following code descriptions are only suitable for dedicated load balancers.

+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
| Module                | Status Code           | Type                  | Error Code            | Possible Cause        |
+=======================+=======================+=======================+=======================+=======================+
| Public                | 400                   | Bad request           | ELB.8902              | Malformed request URI |
|                       |                       |                       |                       | or body.              |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | Invalid **admin       |
|                       |                       |                       |                       | \_state_up** value.   |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | Invalid parameters.   |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | Batch operations are  |
|                       |                       |                       |                       | not allowed.          |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | Failed to verify the  |
|                       |                       |                       |                       | parameters.           |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | Incorrect request     |
|                       |                       |                       |                       | method, for example,  |
|                       |                       |                       |                       | updating attributes   |
|                       |                       |                       |                       | that can be specified |
|                       |                       |                       |                       | during creation only. |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The network is not    |
|                       |                       |                       |                       | external (the value   |
|                       |                       |                       |                       | of                    |
|                       |                       |                       |                       | **router:external**   |
|                       |                       |                       |                       | is set to **false**). |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The IaaS OpenStack    |
|                       |                       |                       |                       | network port has no   |
|                       |                       |                       |                       | floating IP address   |
|                       |                       |                       |                       | bound.                |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The requested         |
|                       |                       |                       |                       | floating IP address   |
|                       |                       |                       |                       | is not in the IP      |
|                       |                       |                       |                       | address range of the  |
|                       |                       |                       |                       | external network.     |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | Invalid fixed IP      |
|                       |                       |                       |                       | address.              |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The router port does  |
|                       |                       |                       |                       | not have a fixed IP   |
|                       |                       |                       |                       | address.              |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The subnet for the    |
|                       |                       |                       |                       | router interface must |
|                       |                       |                       |                       | have a gateway IP     |
|                       |                       |                       |                       | address.              |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       | 401                   | Unauthorized          | SYS.0401              | Authentication        |
|                       |                       |                       |                       | required.             |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       | 403                   | Forbidden             | ELB.8903              | The URI does not      |
|                       |                       |                       |                       | exist.                |
|                       |                       |                       |                       |                       |
|                       |                       |                       |                       | The resource cannot   |
|                       |                       |                       |                       | be found.             |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       | SYS.0403              | Authentication        |
|                       |                       |                       |                       | required.             |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       | 404                   | Not Found             | ELB.8904              | The URI does not      |
|                       |                       |                       |                       | exist.                |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The resource cannot   |
|                       |                       |                       |                       | be found.             |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The port UUID is not  |
|                       |                       |                       |                       | valid.                |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       | 409                   | Conflict              | ELB.8907              | The port is already   |
|                       |                       |                       |                       | in use.               |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The IP address is     |
|                       |                       |                       |                       | already in use.       |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The IP address pool   |
|                       |                       |                       |                       | cannot contain        |
|                       |                       |                       |                       | gateway and broadcast |
|                       |                       |                       |                       | addresses.            |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The requested         |
|                       |                       |                       |                       | floating IP address   |
|                       |                       |                       |                       | is already in use.    |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       |                       | The internal IaaS     |
|                       |                       |                       |                       | OpenStack network     |
|                       |                       |                       |                       | port and fixed IP     |
|                       |                       |                       |                       | address are already   |
|                       |                       |                       |                       | associated with       |
|                       |                       |                       |                       | another floating IP   |
|                       |                       |                       |                       | addresses.            |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       | ELB.8905              | The quota is used up. |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       | 500                   | Internal server error | ELB.8906              | Internal IaaS         |
|                       |                       |                       |                       | OpenStack network     |
|                       |                       |                       |                       | error.                |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
| Load balancer         | 400                   | Bad request           | ELB.8931              | The subnet IP version |
|                       |                       |                       |                       | is not the same.      |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
|                       |                       |                       | ELB.8932              | IPv6 subnets are not  |
|                       |                       |                       |                       | supported, but the    |
|                       |                       |                       |                       | value of              |
|                       |                       |                       |                       | **ip                  |
|                       |                       |                       |                       | v6_vip_virsubnet_id** |
|                       |                       |                       |                       | is not **null**.      |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
| Backend server        | 400                   | Bad request           | ELB.8933              | IPv6 subnets are not  |
|                       |                       |                       |                       | supported, but        |
|                       |                       |                       |                       | backend servers use   |
|                       |                       |                       |                       | IPv6 addresses.       |
+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+

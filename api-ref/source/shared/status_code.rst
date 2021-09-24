.. _shared_lb_status_code:

HTTP Status Codes of Shared Load Balancers
==========================================

The following code descriptions are only suitable for shared load balancers.

.. table:: **Table 1** Normal response codes

   =========== ========== ========================================
   Status Code Type       Description
   =========== ========== ========================================
   200         OK         Normal response to GET and PUT requests.
   201         Created    Normal response to POST requests.
   204         No Content Normal response to DELETE requests.
   =========== ========== ========================================

.. table:: **Table 2** Error codes

   +-------------+------------------------+---------------------------------------+
   | Status Code | Type                   | Possible Cause                        |
   +=============+========================+=======================================+
   | 400         | Bad request            | Malformed request URI or body.        |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Invalid **admin \_state_up** value.   |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Invalid parameters.                   |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Batch operations are not allowed.     |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Failed to verify the parameters.      |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Incorrect request method, for         |
   |             |                        | example, updating attributes that can |
   |             |                        | be specified during creation only.    |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The network is not external (the      |
   |             |                        | value of **router:external** is set   |
   |             |                        | to **false**).                        |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The IaaS OpenStack network port has   |
   |             |                        | no floating IP address bound.         |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The requested floating IP address is  |
   |             |                        | not in the IP address range of the    |
   |             |                        | external network.                     |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Invalid fixed IP address.             |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The router port does not have a fixed |
   |             |                        | IP address.                           |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The subnet for the router interface   |
   |             |                        | must have a gateway IP address.       |
   +-------------+------------------------+---------------------------------------+
   | 401         | Unauthorized           | Authentication required.              |
   +-------------+------------------------+---------------------------------------+
   | 403         | Forbidden              | The URI does not exist.               |
   |             |                        |                                       |
   |             |                        | The resource cannot be found.         |
   +-------------+------------------------+---------------------------------------+
   | 404         | Not Found              | The URI does not exist.               |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The resource cannot be found.         |
   +-------------+------------------------+---------------------------------------+
   |             |                        | Invalid port ID.                      |
   +-------------+------------------------+---------------------------------------+
   | 409         | Conflict               | The port is already in use.           |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The IP address is already in use.     |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The IP address pool cannot contain    |
   |             |                        | gateway and broadcast addresses.      |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The requested floating IP address is  |
   |             |                        | already in use.                       |
   +-------------+------------------------+---------------------------------------+
   |             |                        | The internal IaaS OpenStack network   |
   |             |                        | port and fixed IP address are already |
   |             |                        | associated with another floating IP   |
   |             |                        | addresses.                            |
   +-------------+------------------------+---------------------------------------+
   | 500         | Internal server error. | Internal IaaS OpenStack network       |
   |             |                        | error.                                |
   +-------------+------------------------+---------------------------------------+
   | 503         | Service unavailable    | Failed to assign the MAC address.     |
   +-------------+------------------------+---------------------------------------+

.. table:: **Table 3** Error codes

   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Module            | HTTP Status Code | Error Code | Error Message             | Description                   | Handling Measure  |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Load balancer     | 400              | ELB.0002   | RequestBody is            | The request body              | Set the parameter |
   |                   |                  |            | null or                   | is empty.                     | by following the  |
   |                   |                  |            | empty,request is          |                               | instructions in   |
   |                   |                  |            | invalid.                  |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 401              | ELB.1102   | Token is error,           | Empty token.                  | Use a correct     |
   |                   |                  |            | Authentication            |                               | token that has    |
   |                   |                  |            | required.                 |                               | not expired.      |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | RequestBody is            | Failed to convert             | Set the parameter |
   |                   |                  |            | null, request is          | the request body.             | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **vip_subnet_id**             | Set the parameter |
   |                   |                  |            | loadbalanc                | in the request                | by following the  |
   |                   |                  |            | er[vip_subnet_id]         | body is empty.                | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.1202   | 1.decoded token           | -  The token is               | Check the         |
   |                   |                  |            | is null.                  |    empty.                     | enterprise        |
   |                   |                  |            |                           | -  An error                   | project ID.       |
   |                   |                  |            | 2.check                   |    occurred                   |                   |
   |                   |                  |            | EnterpriseProject         |    during                     |                   |
   |                   |                  |            | is error.                 |    verification               |                   |
   |                   |                  |            |                           |    of **ep_id**.              |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9802   | Policy doesn't            | Authentication                | Check whether you |
   |                   |                  |            | allow                     | failure                       | have the          |
   |                   |                  |            | elb:l                     |                               | permission to     |
   |                   |                  |            | oadbalancers:list         |                               | perform this      |
   |                   |                  |            | to be performed.          |                               | operation.        |
   |                   |                  |            |                           |                               |                   |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9803   | Policy doesn't            | Authentication                | Check whether you |
   |                   |                  |            | allow                     | failure                       | have the          |
   |                   |                  |            | elb:l                     |                               | permission to     |
   |                   |                  |            | oadbalancers:list         |                               | perform this      |
   |                   |                  |            | to be performed.          |                               | operation.        |
   |                   |                  |            |                           |                               |                   |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9804   | Policy doesn't            | Authentication                | Check whether you |
   |                   |                  |            | allow                     | failure                       | have the          |
   |                   |                  |            | elb:l                     |                               | permission to     |
   |                   |                  |            | oadbalancers:list         |                               | perform this      |
   |                   |                  |            | to be performed.          |                               | operation.        |
   |                   |                  |            |                           |                               |                   |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0004   | Api response is           | The response                  | Contact customer  |
   |                   |                  |            | null or invaild.          | returned by                   | service.          |
   |                   |                  |            |                           | Neutron is                    |                   |
   |                   |                  |            |                           | **null**.                     |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9899   | The                       | Combined API                  | Rectify the fault |
   |                   |                  |            | default_tls_container_ref | failed to send                | based on the      |
   |                   |                  |            | field of the              | the request to                | error             |
   |                   |                  |            | TERMINATED_HTTPS          | Neutron.                      | information.      |
   |                   |                  |            | listener does not         |                               |                   |
   |                   |                  |            | allow updating to         |                               |                   |
   |                   |                  |            | null                      |                               |                   |
   |                   |                  |            |                           |                               |                   |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | resources:                |                               | customer service. |
   |                   |                  |            | ['loadbalancer'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.1204   | Bind fail.                | Failed to                     | Contact customer  |
   |                   |                  |            |                           | associate the                 | service.          |
   |                   |                  |            |                           | load balancer                 |                   |
   |                   |                  |            |                           | with the                      |                   |
   |                   |                  |            |                           | enterprise                    |                   |
   |                   |                  |            |                           | project.                      |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | Ep_id is not              | **ep_id** in the              | Check the         |
   |                   |                  |            | uuid.                     | URI is not a                  | enterprise        |
   |                   |                  |            |                           | valid UUID.                   | project ID.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9806   | Loadbalancer_id           | **                            | Check whether the |
   |                   |                  |            | in url is null or         | loadbalancer_id**             | load balancer ID  |
   |                   |                  |            | empty.                    | in the URI is                 | in the URL is     |
   |                   |                  |            |                           | empty.                        | correct.          |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 404              | ELB.9800   | Resource could            | The specified                 | Check the load    |
   |                   |                  |            | not be found.             | load balancer                 | balancer ID.      |
   |                   |                  |            |                           | does not exist                |                   |
   |                   |                  |            |                           | when **ep_id** is             |                   |
   |                   |                  |            |                           | queried.                      |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9808   | Tenant_id in              | The value of                  | Check whether     |
   |                   |                  |            | token mismatches          | **tenant_id** in              | parameter         |
   |                   |                  |            | with tenant_id in         | the token is                  | **tenant_id** in  |
   |                   |                  |            | url.                      | different from                | the token and URL |
   |                   |                  |            |                           | that in the URL.              | is correct.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9801   | Not be list               | In the                        | Check whether the |
   |                   |                  |            | action,                   | fine-grained                  | parameters in the |
   |                   |                  |            | ente                      | authorization                 | request for       |
   |                   |                  |            | rprise_project_id         | scenario, the                 | querying the load |
   |                   |                  |            | must not be null.         | enterprise ID is              | balancers are     |
   |                   |                  |            |                           | not transmitted               | correct.          |
   |                   |                  |            |                           | in the request                |                   |
   |                   |                  |            |                           | for querying the              |                   |
   |                   |                  |            |                           | load balancers.               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Listener          | 400              | ELB.0002   | Listener is null,         | The request body              | Set the parameter |
   |                   |                  |            | request is                | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **protocol** in               | Set the parameter |
   |                   |                  |            | l                         | the request body              | by following the  |
   |                   |                  |            | istener[protocol]         | is empty.                     | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **protocol_port**             | Set the parameter |
   |                   |                  |            | listen                    | is empty.                     | by following the  |
   |                   |                  |            | er[protocol_port]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **                            | Set the parameter |
   |                   |                  |            | listener                  | loadbalancer_id**             | by following the  |
   |                   |                  |            | [loadbalancer_id]         | is empty.                     | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.6200   | Load Balaner              | The port number               | Change the port   |
   |                   |                  |            | \**\* already has         | is in use.                    | number.           |
   |                   |                  |            | a listener with           |                               |                   |
   |                   |                  |            | protocol_port of          |                               |                   |
   |                   |                  |            | \***.                     |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | resour                    |                               | customer service. |
   |                   |                  |            | ces:['listener'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Backend server    | 400              | ELB.0002   | Pool is null,             | The request body              | Set the parameter |
   | group             |                  |            | request is                | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **protocol** is               | Set the parameter |
   |                   |                  |            | pool[protocol] is         | empty.                        | by following the  |
   |                   |                  |            | null, this is a           |                               | instructions in   |
   |                   |                  |            | required                  |                               | this guide.       |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **lb_algorithm**              | Set the parameter |
   |                   |                  |            | p                         | is empty.                     | by following the  |
   |                   |                  |            | ool[lb_algorithm]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | re                        |                               | customer service. |
   |                   |                  |            | sources:['pool'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **listener_id**               | Set the parameter |
   |                   |                  |            | pool                      | is empty.                     | by following the  |
   |                   |                  |            | [loadbalancer_id]         |                               | instructions in   |
   |                   |                  |            | and                       |                               | this guide.       |
   |                   |                  |            | pool[listener_id]         |                               |                   |
   |                   |                  |            | both are null,            |                               |                   |
   |                   |                  |            | this has at least         |                               |                   |
   |                   |                  |            | one parameter.            |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Backend server    | 400              | ELB.9805   | RequestBody               | **sess                        | Set the parameter |
   |                   |                  |            | pool[session_p            | ion_persistence**             | by following the  |
   |                   |                  |            | ersistence][type]         | is empty.                     | instructions in   |
   |                   |                  |            | is null. when             |                               | this guide.       |
   |                   |                  |            | pool[ses                  |                               |                   |
   |                   |                  |            | sion_persistence]         |                               |                   |
   |                   |                  |            | exists, this is a         |                               |                   |
   |                   |                  |            | required                  |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | Member is                 | The request body              | Set the parameter |
   |                   |                  |            | null,request is           | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **address** is                | Set the parameter |
   |                   |                  |            | member[address]           | empty.                        | by following the  |
   |                   |                  |            | is null, this is          |                               | instructions in   |
   |                   |                  |            | a required                |                               | this guide.       |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | reso                      |                               | customer service. |
   |                   |                  |            | urces:['member'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | The value of                  | Set the parameter |
   |                   |                  |            | member[address]'s         | **address**                   | by following the  |
   |                   |                  |            | length is %s,             | contains more                 | instructions in   |
   |                   |                  |            | greater than 64.          | than 64                       | this guide.       |
   |                   |                  |            |                           | characters.                   |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **protocol_port**             | Set the parameter |
   |                   |                  |            | memb                      | is empty.                     | by following the  |
   |                   |                  |            | er[protocol_port]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Health check      | 400              | ELB.9805   | RequestBody               | **subnet_id** is              | Set the parameter |
   |                   |                  |            | member[subnet_id]         | empty.                        | by following the  |
   |                   |                  |            | is null, this is          |                               | instructions in   |
   |                   |                  |            | a required                |                               | this guide.       |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | healthmonitor is          | The request body              | Set the parameter |
   |                   |                  |            | null,request is           | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **delay** is                  | Set the parameter |
   |                   |                  |            | hea                       | empty.                        | by following the  |
   |                   |                  |            | lthmonitor[delay]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **max_retries**               | Set the parameter |
   |                   |                  |            | healthmon                 | is empty.                     | by following the  |
   |                   |                  |            | itor[max_retries]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **pool_id** is                | Set the parameter |
   |                   |                  |            | healt                     | empty.                        | by following the  |
   |                   |                  |            | hmonitor[pool_id]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | resources:[               |                               | customer service. |
   |                   |                  |            | 'healthmonitor'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **timeout** is                | Set the parameter |
   |                   |                  |            | healt                     | empty.                        | by following the  |
   |                   |                  |            | hmonitor[timeout]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Forwarding policy | 400              | ELB.9805   | RequestBody               | **type** is                   | Set the parameter |
   |                   |                  |            | he                        | empty.                        | by following the  |
   |                   |                  |            | althmonitor[type]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | l7policy is               | The request body              | Set the parameter |
   |                   |                  |            | null,request is           | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | resource                  |                               | customer service. |
   |                   |                  |            | s:['l7policiey'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **listener_id**               | Set the parameter |
   |                   |                  |            | l7po                      | is empty.                     | by following the  |
   |                   |                  |            | licy[listener_id]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Forwarding rule   | 400              | ELB.9805   | RequestBody               | **action** is                 | Set the parameter |
   |                   |                  |            | l7policy[action]          | empty.                        | by following the  |
   |                   |                  |            | is null, this is          |                               | instructions in   |
   |                   |                  |            | a required                |                               | this guide.       |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | Rule is                   | The request body              | Set the parameter |
   |                   |                  |            | null,request is           | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **type** is                   | Set the parameter |
   |                   |                  |            | rule[type] is             | empty.                        | by following the  |
   |                   |                  |            | null, this is a           |                               | instructions in   |
   |                   |                  |            | required                  |                               | this guide.       |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | resources:['              |                               | customer service. |
   |                   |                  |            | l7policieyrule'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **compare_type**              | Set the parameter |
   |                   |                  |            | r                         | is empty.                     | by following the  |
   |                   |                  |            | ule[compare_type]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **value** is                  | Set the parameter |
   |                   |                  |            | rule[value] is            | empty.                        | by following the  |
   |                   |                  |            | null, this is a           |                               | instructions in   |
   |                   |                  |            | required                  |                               | this guide.       |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | The parameter                 | Set the parameter |
   |                   |                  |            | rule[value]'s             | value contains                | by following the  |
   |                   |                  |            | length is %s,             | more than 128                 | instructions in   |
   |                   |                  |            | greater than 128.         | characters.                   | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Whitelist         | 400              | ELB.9807   | Quota exceeded            | The quota has                 | To expand the     |
   |                   |                  |            | for                       | been used up.                 | quota, contact    |
   |                   |                  |            | resourc                   |                               | customer service. |
   |                   |                  |            | es:['whitelist'].         |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | whitelist is              | The request body              | Set the parameter |
   |                   |                  |            | null,request is           | is empty.                     | by following the  |
   |                   |                  |            | invalid.                  |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | **listener_id**               | Set the parameter |
   |                   |                  |            | white                     | is empty.                     | by following the  |
   |                   |                  |            | list[listener_id]         |                               | instructions in   |
   |                   |                  |            | is null, this is          |                               | this guide.       |
   |                   |                  |            | a required                |                               |                   |
   |                   |                  |            | parameter.                |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9805   | RequestBody               | The value of                  | Set the parameter |
   |                   |                  |            | whiteli                   | **listener_id**               | by following the  |
   |                   |                  |            | st[listener_id]'s         | contains more                 | instructions in   |
   |                   |                  |            | length is %s,             | than 255                      | this guide.       |
   |                   |                  |            | greater than 255.         | characters.                   |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Label Management  | 400              | ELB.0002   | RequestBody is            | Invalid request               | Set the parameter |
   |                   |                  |            | null or empty.            | body.                         | by following the  |
   |                   |                  |            |                           |                               | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 401              | ELB.1102   | Token is error,           | Invalid token.                | Use a correct     |
   |                   |                  |            | Authentication            |                               | token that has    |
   |                   |                  |            | required.                 |                               | not expired.      |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.0002   | L                         | Invalid request               | Set the parameter |
   |                   |                  |            | ogTankRequestBody         | body.                         | by following the  |
   |                   |                  |            | is null, request          |                               | instructions in   |
   |                   |                  |            | is invalid.               |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   |                  |            | LoadbalancerId in         | **                            | Set the parameter |
   |                   |                  |            | requestBody is            | loadbalancer_id**             | by following the  |
   |                   |                  |            | null.                     | in the request                | instructions in   |
   |                   |                  |            |                           | body is empty.                | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   |                  |            | LoggroupId in             | **log_group_id**              | Set the parameter |
   |                   |                  |            | requestBody is            | in the request                | by following the  |
   |                   |                  |            | null.                     | body is empty.                | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   |                  |            | LogtopicId in             | **log_topic_id**              | Set the parameter |
   |                   |                  |            | requestBody is            | in the request                | by following the  |
   |                   |                  |            | null.                     | body is empty.                | instructions in   |
   |                   |                  |            |                           |                               | this guide.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9802   | Policy doesn't            | Permission                    | Check whether you |
   |                   |                  |            | allow                     | verification                  | have the          |
   |                   |                  |            | el                        | failed.                       | permission to     |
   |                   |                  |            | b:logtanks:create         |                               | perform this      |
   |                   |                  |            | to be performed.          |                               | operation.        |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9803   | Policy doesn't            | Permission                    | Check whether you |
   |                   |                  |            | allow                     | verification                  | have the          |
   |                   |                  |            | elb:l                     | failed.                       | permission to     |
   |                   |                  |            | oadbalancers:list         |                               | perform this      |
   |                   |                  |            | to be performed.          |                               | operation.        |
   |                   |                  |            |                           |                               |                   |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 403              | ELB.9804   | Policy doesn't            | Permission                    | Check whether you |
   |                   |                  |            | allow                     | verification                  | have the          |
   |                   |                  |            | elb:l                     | failed.                       | permission to     |
   |                   |                  |            | oadbalancers:list         |                               | perform this      |
   |                   |                  |            | to be performed.          |                               | operation.        |
   |                   |                  |            |                           |                               |                   |
   |                   |                  |            | etc.                      |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.9899   | The                       | Parameter                     | Rectify the fault |
   |                   |                  |            | default_tls_container_ref | **default_tls_container_ref** | based on the      |
   |                   |                  |            |                           |                               | error             |
   |                   |                  |            | field of the              | cannot be left                | information.      |
   |                   |                  |            | TERMINATED_HTTPS          | blank.                        |                   |
   |                   |                  |            | listener does not         |                               |                   |
   |                   |                  |            | allow updating to         |                               |                   |
   |                   |                  |            | null.                     |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | Certificate       | 400              | ELB.1001   | Request                   | Invalid                       | Enter a valid     |
   |                   |                  |            | parameters                | parameter.                    | parameter.        |
   |                   |                  |            | invalid.                  |                               |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5010   | The certificate           | The certificate               | Enter a valid     |
   |                   |                  |            | URL contains more         | URL contains more             | certificate URL.  |
   |                   |                  |            | than four parts.          | than four parts.              |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5020   | The certificate           | The certificate               | Enter a valid     |
   |                   |                  |            | ID must be 32             | ID is not a                   | certificate ID.   |
   |                   |                  |            | characters.               | 32-character                  |                   |
   |                   |                  |            |                           | string.                       |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5030   | Incorrect                 | Incorrect                     | Enter a valid     |
   |                   |                  |            | certificate URL.          | certificate URL.              | certificate URL.  |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 404              | ELB.5040   | The certificate           | The certificate               | Ensure that the   |
   |                   |                  |            | does not exist.           | does not exist.               | certificate       |
   |                   |                  |            |                           |                               | exists.           |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5131   | Failed to query           | Failed to query               | Contact customer  |
   |                   |                  |            | the certificate           | the certificate               | service.          |
   |                   |                  |            | quota.                    | quota.                        |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5141   | Failed to query           | Failed to query               | Contact customer  |
   |                   |                  |            | the user                  | the used                      | service.          |
   |                   |                  |            | certificate               | certificate                   |                   |
   |                   |                  |            | quota.                    | quota.                        |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5151   | The certificate           | The quota has                 | Ensure that the   |
   |                   |                  |            | quantity exceeds          | been used up.                 | quantity of       |
   |                   |                  |            | the quota.                |                               | certificates is   |
   |                   |                  |            |                           |                               | less than the     |
   |                   |                  |            |                           |                               | quota.            |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.1011   | Private_key or            | Invalid public or             | Enter a valid     |
   |                   |                  |            | certificate               | private key of                | public or private |
   |                   |                  |            | content is not            | the server                    | key.              |
   |                   |                  |            | valid.                    | certificate.                  |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5051   | CA certificate            | Invalid CA                    | Enter valid       |
   |                   |                  |            | content is not            | certificate                   | certificate       |
   |                   |                  |            | valid.                    | content.                      | content.          |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5002   | Failed to delete          | Failed to delete              | Contact customer  |
   |                   |                  |            | the certificate.          | the certificate.              | service.          |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5033   | Failed to update          | Failed to modify              | Contact customer  |
   |                   |                  |            | certificate.              | the certificate.              | service.          |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5013   | Private_key or            | Invalid public or             | Enter a valid     |
   |                   |                  |            | certificate               | private key of                | public or private |
   |                   |                  |            | content is not            | the server                    | key.              |
   |                   |                  |            | valid.                    | certificate.                  |                   |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5053   | CA certificate            | Invalid CA                    | Enter valid       |
   |                   |                  |            | content is not            | certificate                   | certificate       |
   |                   |                  |            | valid.                    | content.                      | content.          |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   |                   | 400              | ELB.5004   | Invalid search            | Invalid query                 | Ensure that the   |
   |                   |                  |            | criteria.                 | condition.                    | query condition   |
   |                   |                  |            |                           |                               | is correct.       |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+
   | API version       | 404              | ELB.1110   | version not               | The API version               | Contact customer  |
   |                   |                  |            | found.                    | does not exist.               | service.          |
   +-------------------+------------------+------------+---------------------------+-------------------------------+-------------------+


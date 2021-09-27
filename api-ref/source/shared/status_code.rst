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

.. csv-table:: **Table 3** Error codes
   :delim: ;
   :header: Module, HTTP Status Code, Error Code, Error Message, Description, Handling Measure

   Load balancer;400;ELB.0002;RequestBody is null or empty,request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;401;ELB.1102;Token is error, Authentication required.;Empty token.;Use a correct token that has not expired.
   ;400;ELB.0002;RequestBody is null, request is invalid.;Failed to convert the request body.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody loadbalancer[vip_subnet_id] is null, this is a required parameter.;vip_subnet_id in the request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.1202;1.decoded token is null. 2.checkEnterpriseProject is error.;The token is empty. An error occurred during verification of ep_id.;Check the enterprise project ID.
   ;403;ELB.9802;Policy doesn't allow elb:loadbalancers:list to be performed.;Authentication failure;Check whether you have the permission to perform this operation.
   ;403;ELB.9803;Policy doesn't allow elb:loadbalancers:list to be performed.;Authentication failure;Check whether you have the permission to perform this operation.
   ;403;ELB.9804;Policy doesn't allow elb:loadbalancers:list to be performed.;Authentication failure;Check whether you have the permission to perform this operation.
   ;400;ELB.0004;Api response is null or invaild.;The response returned by Neutron is null.;Contact customer service.
   ;400;ELB.9899;The default_tls_container_ref field of the TERMINATED_HTTPS listener does not allow updating to null;Combined API failed to send the request to Neutron.;Rectify the fault based on the error information.
   ;400;ELB.9807;Quota exceeded for resources:['loadbalancer'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.1204;Bind fail.;Failed to associate the load balancer with the enterprise project.;Contact customer service.
   ;400;ELB.9805;Ep_id is not uuid.;ep_id in the URI is not a valid UUID.;Check the enterprise project ID.
   ;400;ELB.9806;Loadbalancer_id in url is null or empty.;loadbalancer_id in the URI is empty.;Check whether the load balancer ID in the URL is correct.
   ;404;ELB.9800;Resource could not be found.;The specified load balancer does not exist when ep_id is queried.;Check the load balancer ID.
   ;400;ELB.9808;Tenant_id in token mismatches with tenant_id in url.;The value of tenant_id in the token is different from that in the URL.;Check whether parameter tenant_id in the token and URL is correct.
   ;403;ELB.9801;Not be list action, enterprise_project_id must not be null.;In the fine-grained authorization scenario, the enterprise ID is not transmitted in the request for querying the load balancers.;Check whether the parameters in the request for querying the load balancers are correct.
   Listener;400;ELB.0002;Listener is null, request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody listener[protocol] is null, this is a required parameter.;protocol in the request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody listener[protocol_port] is null, this is a required parameter.;protocol_port is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody listener[loadbalancer_id] is null, this is a required parameter.;loadbalancer_id is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.6200;Load Balaner *** already has a listener with protocol_port of ***.;The port number is in use.;Change the port number.
   ;400;ELB.9807;Quota exceeded for resources:['listener'].;The quota has been used up.;To expand the quota, contact customer service.
   Backend server group;400;ELB.0002;Pool is null, request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody pool[protocol] is null, this is a required parameter.;protocol is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody pool[lb_algorithm] is null, this is a required parameter.;lb_algorithm is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9807;Quota exceeded for resources:['pool'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.9805;RequestBody pool[loadbalancer_id] and pool[listener_id] both are null, this has at least one parameter.;listener_id is empty.;Set the parameter by following the instructions in this guide.
   Backend server;400;ELB.9805;RequestBody pool[session_persistence][type] is null. when pool[session_persistence] exists, this is a required parameter.;session_persistence is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0002;Member is null,request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody member[address] is null, this is a required parameter.;address is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9807;Quota exceeded for resources:['member'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.9805;RequestBody member[address]'s length is %s, greater than 64.;The value of address contains more than 64 characters.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody member[protocol_port] is null, this is a required parameter.;protocol_port is empty.;Set the parameter by following the instructions in this guide.
   Health check;400;ELB.9805;RequestBody member[subnet_id] is null, this is a required parameter.;subnet_id is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0002;healthmonitor is null,request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody healthmonitor[delay] is null, this is a required parameter.;delay is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody healthmonitor[max_retries] is null, this is a required parameter.;max_retries is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody healthmonitor[pool_id] is null, this is a required parameter.;pool_id is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9807;Quota exceeded for resources:['healthmonitor'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.9805;RequestBody healthmonitor[timeout] is null, this is a required parameter.;timeout is empty.;Set the parameter by following the instructions in this guide.
   Forwarding policy;400;ELB.9805;RequestBody healthmonitor[type] is null, this is a required parameter.;type is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0002;l7policy is null,request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9807;Quota exceeded for resources:['l7policiey'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.9805;RequestBody l7policy[listener_id] is null, this is a required parameter.;listener_id is empty.;Set the parameter by following the instructions in this guide.
   Forwarding rule;400;ELB.9805;RequestBody l7policy[action] is null, this is a required parameter.;action is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0002;Rule is null,request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody rule[type] is null, this is a required parameter.;type is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9807;Quota exceeded for resources:['l7policieyrule'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.9805;RequestBody rule[compare_type] is null, this is a required parameter.;compare_type is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody rule[value] is null, this is a required parameter.;value is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody rule[value]'s length is %s, greater than 128.;The parameter value contains more than 128 characters.;Set the parameter by following the instructions in this guide.
   Whitelist;400;ELB.9807;Quota exceeded for resources:['whitelist'].;The quota has been used up.;To expand the quota, contact customer service.
   ;400;ELB.0002;whitelist is null,request is invalid.;The request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody whitelist[listener_id] is null, this is a required parameter.;listener_id is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.9805;RequestBody whitelist[listener_id]'s length is %s, greater than 255.;The value of listener_id contains more than 255 characters.;Set the parameter by following the instructions in this guide.
   Label Management;400;ELB.0002;RequestBody is null or empty.;Invalid request body.;Set the parameter by following the instructions in this guide.
   ;401;ELB.1102;Token is error, Authentication required.;Invalid token.;Use a correct token that has not expired.
   ;400;ELB.0002;LogTankRequestBody is null, request is invalid.;Invalid request body.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0003;LoadbalancerId in requestBody is null.;loadbalancer_id in the request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0004;LoggroupId in requestBody is null.;log_group_id in the request body is empty.;Set the parameter by following the instructions in this guide.
   ;400;ELB.0005;LogtopicId in requestBody is null.;log_topic_id in the request body is empty.;Set the parameter by following the instructions in this guide.
   ;403;ELB.9802;Policy doesn't allow elb:logtanks:create to be performed.;Permission verification failed.;Check whether you have the permission to perform this operation.
   ;403;ELB.9803;Policy doesn't allow elb:loadbalancers:list to be performed.;Permission verification failed.;Check whether you have the permission to perform this operation.
   ;400;ELB.9899;The default_tls_container_ref field of the TERMINATED_HTTPS listener does not allow updating to null.;Parameter default_tls_container_ref cannot be left blank.;Rectify the fault based on the error information.
   Certificate;400;ELB.1001;Request parameters invalid.;Invalid parameter.;Enter a valid parameter.
   ;400;ELB.5010;The certificate URL contains more than four parts.;The certificate URL contains more than four parts.;Enter a valid certificate URL.
   ;400;ELB.5020;The certificate ID must be 32 characters.;The certificate ID is not a 32-character string.;Enter a valid certificate ID.
   ;400;ELB.5030;Incorrect certificate URL.;Incorrect certificate URL.;Enter a valid certificate URL.
   ;404;ELB.5040;The certificate does not exist.;The certificate does not exist.;Ensure that the certificate exists.
   ;400;ELB.5131;Failed to query the certificate quota.;Failed to query the certificate quota.;Contact customer service.
   ;400;ELB.5141;Failed to query the user certificate quota.;Failed to query the used certificate quota.;Contact customer service.
   ;400;ELB.5151;The certificate quantity exceeds the quota.;The quota has been used up.;Ensure that the quantity of certificates is less than the quota.
   ;400;ELB.1011;Private_key or certificate content is not valid.;Invalid public or private key of the server certificate.;Enter a valid public or private key.
   ;400;ELB.5051;CA certificate content is not valid.;Invalid CA certificate content.;Enter valid certificate content.
   ;400;ELB.5002;Failed to delete the certificate.;Failed to delete the certificate.;Contact customer service.
   ;400;ELB.5033;Failed to update certificate.;Failed to modify the certificate.;Contact customer service.
   ;400;ELB.5013;Private_key or certificate content is not valid.;Invalid public or private key of the server certificate.;Enter a valid public or private key.
   ;400;ELB.5053;CA certificate content is not valid.;Invalid CA certificate content.;Enter valid certificate content.
   ;400;ELB.5004;Invalid search criteria.;Invalid query condition.;Ensure that the query condition is correct.
   Tag;400;VPC.1801;The ID is incorrect.;resource id is invalid/Getting id is invalid.;Use a correct resource ID.
   ;400;VPC.1801;An action error occurs.;action is invalid.;Ensure that the value of action is create or delete.
   ;400;VPC.1801;The key length is invalid.;Tag length is invalid. The key length must be in range [1,36] and value in range [0,43];Input a valid key.
   ;400;VPC.0007;The project ID is incorrect.;urlTenantId is not equal token TenantId.;Check the project ID.
   ;401;VPC.0008;The token in the request is invalid or the request does not contain the token.;Invalid token in the header./Authorization information is wrong.;Check whether the token is valid.
   ;400;VPC.1801;The value length is invalid.;Tag length is invalid. The key length must be in range [1,36] and value in range [0,43];Input a valid value.
   ;400;VPC.1801;The key or value contains invalid characters.;InvalidInput/Tag value xxx is invalid.;Check the validity of the key or value.
   ;400;VPC.1801;The key or value is left blank.;Tag xxx can not be null.;Check whether the key or value is left blank.
   ;400;VPC.1801;The tag is null.;Tag can not be null.;Check whether the tag is null.
   ;400;VPC.1801;A resource type error occurs.;Resource xxx is invalid.;Ensure that the value of resource_type is loadbalancers or listeners.
   ;400;VPC.1801;The total number of tags added at a time exceeds 10.;number of tags exceeds max unm of 10.;Reduce the number of tags.
   ;400;VPC.1814;The total number of existing tags and newly added tags exceeds 10.;Invalid input for operation: resource_id: XXXX, number of tags exceed max num of 10.;Reduce the number of tags.
   ;400;VPC.1814;The key values of newly added tags are duplicate.;Invalid input for operation: tags key is duplicated.;Change the tag values.
   ;400;VPC.1814;The resource ID does not exist.;Resource XXX XXX could not be found.;Check whether the resource is available.
   ;400;VPC.1814;The specified key to be deleted does not exist, or the key is an empty string.;The resource could not be found.;Enter a correct key and send the request again.
   ;400;VPC.1814;More than 10 tags are added to a specified resource.;Invalid input for operation:resource_id:xxx, number of tags exceeds max num of 10.;Each resource supports up to 10 tags.
   ;400;VPC.1801;Tags are duplicate.;Tag key is repeated.;Delete duplicate tags and resend the request.
   ;500;;The request format is incorrect.;Internal Server Error.;Use the correct request body format.
   API Version;404;ELB.1110;version not found.;The API version does not exist.;Contact customer service.

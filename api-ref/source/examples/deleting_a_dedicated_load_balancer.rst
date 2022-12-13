:original_name: elb_eg_v3_0003.html

.. _elb_eg_v3_0003:

Deleting a Dedicated Load Balancer
==================================

Scenarios
---------

Call APIs to delete a dedicated load balancer.

Before you delete a dedicated load balancer, delete all resources associated with it. :ref:`Figure 1 <elb_eg_v3_0003__fig14527132320389>` shows the associated resources.

.. _elb_eg_v3_0003__fig14527132320389:

.. figure:: /_static/images/en-us_image_0294158472.png
   :alt: **Figure 1** Resources associated with a dedicated load balancer

   **Figure 1** Resources associated with a dedicated load balancer

Procedure
---------

Perform the following steps to delete the associated resources and the load balancer. Skip the corresponding step if the associated resources do not exist. For example, you can skip :ref:`1 <elb_eg_v3_0003__li693163653915>` if no health check is configured.

#. .. _elb_eg_v3_0003__li693163653915:

   Delete the health check configured for each associated backend server group.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/healthmonitors/**\ *{healthmonitor_id}*. *project_id* indicates the project ID, and *healthmonitor_id* indicates the health check ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Remove backend servers from each associated backend server group.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/pools/**\ *{pool_id}*\ **/members/**\ *{member_id}*. *project_id* indicates the project ID, *pool_id* indicates the backend server group ID, and **member_id** indicates the backend server ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Delete each associated backend server group.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/{project_id}/elb/pools/**\ *{pool_id}*. *project_id* indicates the project ID, and *pool_id* indicates the backend server group ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Delete the forwarding rules added to each listener.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/l7policies/**\ *{policy_id}*\ **/rules/**\ *{rule_id}*. *project_id* indicates the project ID, *policy_id* indicates the forwarding policy ID, and *rule_id* indicates the forwarding rule ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Delete the forwarding policies added to each listener.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/l7policies/**\ *{policy_id}*. *project_id* indicates the project ID, and *policy_id* indicates the forwarding policy ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Delete each listener added to the load balancer.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elb/listeners/**\ *{listener_id}*. *project_id* indicates the project ID, and *listener_id* indicates the listener ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

#. Delete the load balancer.

   a. Send **DELETE https://**\ *{elb_endpoint}*\ **/v3/**\ *{project_id}*\ **/elbloadbalancers/**\ *{loadbalancer_id}*. *project_id* indicates the project ID, and *loadbalancer_id* indicates the load balancer ID.
   b. Add **X-Auth-Token** to the request header.
   c. Check the response.

      -  If the request is successful, 204 is returned, and the response body is empty.
      -  If the request is abnormal, locate the fault by referring to :ref:`HTTP Status Codes for Dedicated Load Balancers <elb_gc_0003>`.

:original_name: elb_ug_sj_0002.html

.. _elb_ug_sj_0002:

Viewing Traces
==============

Scenarios
---------

CTS records the operations performed on ELB and allows you to view the operation records of the last seven days on the CTS console. To query these records, perform the following operations.

Procedure
---------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Under **Management & Deployment**, click **Cloud Trace Service**.

#. In the navigation pane on the left, choose **Trace List**.

#. Specify the filters used for querying traces. The following filters are available:


   .. figure:: /_static/images/en-us_image_0129028346.png
      :alt: **Figure 1** Filters

      **Figure 1** Filters

   -  **Trace Type**, **Trace Source**, **Resource Type**, and **Search By**

      Select a filter from the drop-down list.

      If you select **Trace name** for **Search By**, you need to select a specific trace name.

      If you select **Resource ID** for **Search By**, select or enter a specific resource ID.

      If you select **Resource name** for **Search By**, select or enter a specific resource name.

   -  **Operator**: Select a specific operator (at the user level rather than the tenant level).

   -  **Trace Status**: Available options include **All trace statuses**, **Normal**, **Warning**, and **Incident**. You can only select one of them.

   -  Time range: You can query traces generated at any time range of the last seven days.

#. Click |image2| on the left of the required trace to expand its details.


   .. figure:: /_static/images/en-us_image_0153115564.png
      :alt: **Figure 2** Expanding trace details

      **Figure 2** Expanding trace details

#. Click **View Trace** in the **Operation** column to view trace details.


   .. figure:: /_static/images/en-us_image_0153115565.png
      :alt: **Figure 3** View Trace

      **Figure 3** View Trace

   For details about key fields in the trace, see the *Cloud Trace Service User Guide*.

Example Traces
--------------

-  Creating a load balancer

   .. code-block::

      request {"loadbalancer":{"name":"elb-test-zcy","description":"","tenant_id":"05041fffa40025702f6dc009cc6f8f33","vip_subnet_id":"ed04fd93-e74b-4794-b63e-e72baa02a2da","admin_state_up":true}}
      code 201
      source_ip 124.71.93.36
      trace_type ConsoleAction
      event_type system
      project_id 05041fffa40025702f6dc009cc6f8f33
      trace_id b39b21a1-8d49-11ec-b548-2be046112888
      trace_name createLoadbalancer
      resource_type loadbalancer
      trace_rating normal
      api_version v2.0
      service_type ELB
      response {"loadbalancer": {"description": "", "provisioning_status": "ACTIVE", "provider": "vlb", "project_id": "05041fffa40025702f6dc009cc6f8f33", "vip_address": "172.18.0.205", "pools": [], "operating_status": "ONLINE", "name": "elb-test-zcy", "created_at": "2022-02-14T03:53:39", "listeners": [], "id": "7ebe23cd-1d46-4a49-b707-1441c7f0d0d1", "vip_port_id": "5b36ff96-3773-4736-83cf-38c54abedeea", "updated_at": "2022-02-14T03:53:41", "tags": [], "admin_state_up": true, "vip_subnet_id": "ed04fd93-e74b-4794-b63e-e72baa02a2da", "tenant_id": "05041fffa40025702f6dc009cc6f8f33"}}
      resource_id 7ebe23cd-1d46-4a49-b707-1441c7f0d0d1
      tracker_name system
      time 2022/02/14 11:53:42 GMT+08:00
      resource_name elb-test-zcy
      record_time 2022/02/14 11:53:42 GMT+08:00
      request_id
      user {"domain": {"name": "CBUInfo", "id": "0503dda87802345ddafed096d70a960"}, "name": "zcy", "id": "09f106afd2345cdeff5c009c58f5b4a"}

-  Deleting a load balancer

   .. code-block::

      request
      code 204
      source_ip 124.71.93.36
      trace_type ConsoleAction
      event_type system
      project_id 05041fffa40025702f6dc009cc6f8f33
      trace_id 4f838bbf-8d4a-11ec-a1fe-1f93fdaf3bec
      trace_name deleteLoadbalancer
      resource_type loadbalancer
      trace_rating normal
      api_version v2.0
      service_type ELB
      response {"loadbalancer": {"listeners": [], "vip_port_id": "5b36ff96-3773-4736-83cf-38c54abedeea", "tags": [], "tenant_id": "05041fffa40025702f6dc009cc6f8f33", "admin_state_up": true, "id": "7ebe23cd-1d46-4a49-b707-1441c7f0d0d1", "operating_status": "ONLINE", "description": "", "pools": [], "vip_subnet_id": "ed04fd93-e74b-4794-b63e-e72baa02a2da", "project_id": "05041fffa40025702f6dc009cc6f8f33", "provisioning_status": "ACTIVE", "name": "elb-test-zcy", "created_at": "2022-02-14T03:53:39", "vip_address": "172.18.0.205", "updated_at": "2022-02-14T03:53:41", "provider": "vlb"}}
      resource_id 7ebe23cd-1d46-4a49-b707-1441c7f0d0d1
      tracker_name system
      time 2022/02/14 11:58:03 GMT+08:00
      resource_name elb-test-zcy
      record_time 2022/02/14 11:58:03 GMT+08:00
      request_id
      user {"domain": {"name": CBUInfo", "id": "0503dda87802345ddafed096d70a960"}, "name": "zcy", "id": "09f106afd2345cdeff5c009c58f5b4a"}

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0114944782.jpg

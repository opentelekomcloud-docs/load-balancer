:original_name: elb_ug_fz_0004.html

.. _elb_ug_fz_0004:

Preparations for Creating a Load Balancer
=========================================

Before creating a load balancer, you must plan its region, network, protocol, and backend servers.

Region
------

When you select a region, note the following:

-  The region must be close to your users to reduce network latency and improve the download speed.
-  Shared load balancers cannot distribute traffic across regions. When creating a shared load balancer, select the same region as the backend servers.
-  Dedicated load balancers support adding backend servers across VPCs using the IP as a backend function. For details, see :ref:`Configuring Hybrid Load Balancing <elb_ug_hd_0005>`.

AZ
--

Dedicated load balancers can be deployed across AZs. If you select multiple AZs, a load balancer is created in each selected AZ.

Load balancers in these AZs work in active-active or multi-active mode and follow the proximity principle to route traffic. For example, traffic to backend servers in AZ 1 is distributed by the load balancer in AZ 1 or a load balancer in an AZ close to AZ 1.

Select the AZ where backend servers reside to reduce network latency and improve access speed.

If disaster recovery is required, create load balancers based on the scenario:

-  **One load balancer in multiple AZs (disaster recovery at the AZ level)**

   If the number of requests does not exceed what the largest specifications (large II) can handle, you can create a load balancer and select multiple AZs. In this way, if the load balancer in a single AZ is abnormal, the load balancer in other AZs can route the traffic, and disaster recovery can be implemented among multiple AZs.

-  **Multiple load balancers and each load balancer in multiple AZs (disaster recovery at both the load balancer and AZ level)**

   If the number of requests exceeds what the largest specifications (large II) can handle, you can create multiple load balancers and select multiple AZs for each load balancer. In this way, if a single load balancer is abnormal, other load balancers can distribute the traffic, and disaster recovery can be implemented among multiple load balancers and AZs.

.. note::

   -  If requests are from the Internet, the load balancer in each AZ you select routes the requests based on source IP addresses. If you deploy a load balancer in two AZs, the requests the load balancers can handle will be doubled.
   -  For requests from a private network:

      -  If clients are in an AZ you have selected when you create the load balancer, requests are distributed by the load balancer in this AZ. If the load balancer is unhealthy, requests are distributed by the load balancer in another AZ you have selected.

         If the load balancer is healthy but the connections that the load balancer need to handle exceed the amount defined in the specifications, service may be interrupted. To address this issue, you need upgrade specifications.

      -  If clients are in an AZ that is not selected when you create the load balancer, requests are distributed by the load balancer in each AZ you select based on source IP addresses.

Network Type
------------

The network type can be any of the following:

-  If you select the public IPv4 network, the load balancer will have an IPv4 EIP bound to route requests over the Internet.
-  If you select the private IPv4 network, a private IPv4 IP address will be assigned to the load balancer to route requests within a VPC.

Shared load balancers can work in both public and private networks.

-  To route requests over the Internet, you need to bind an EIP to the load balancer. The load balancer also has a private IP address and can route requests in a VPC.
-  To route requests in a VPC, bind only a private IP address to the load balancer.

Specifications
--------------

Dedicated load balancers provide a broad range of specifications to meet your requirements in different scenarios. Specifications for network load balancing are suitable for TCP or UDP requests, while specifications for application load balancing are broadly used to handle HTTP or HTTPS requests. Select appropriate specifications based on your traffic volume and service requirements. The following are some principles for you to select the specifications:

-  For TCP or UDP load balancing, pay attention to the number of concurrent persistent connections, and consider Maximum Connections as a key metric. Estimate the maximum number of concurrent connections that a load balancer can handle in the actual service scenario and select the corresponding specification.
-  For HTTP or HTTPS load balancers, focus more on queries per second (QPS), which determines the service throughput of an application system. Estimate the QPS that a load balancer can handle in the actual service scenario and select the corresponding specification.
-  Use the monitoring data from Cloud Eye to analyze the peak traffic, trend and regularity of the traffic to select the specifications more accurately.

Protocol
--------

ELB provides load balancing at both Layer 4 and Layer 7.

-  If you choose TCP or UDP, the load balancer routes requests directly to backend servers. In this process, the destination IP address in the packets is changed to the IP address of the backend server, and the source IP address to the private IP address of the load balancer. A connection is established after a three-way handshake between the client and the backend server, and the load balancer only forwards the data.


   .. figure:: /_static/images/en-us_image_0238395032.png
      :alt: **Figure 1** Layer-4 load balancing

      **Figure 1** Layer-4 load balancing

-  Load balancing at Layer 7 is also called "content exchange". After the load balancer receives a request, it works as a proxy of backend servers to establish a connection (three-way handshake) with the client and then determines to which backend server the request is to be routed based on the fields in the HTTP/HTTPS request header and the load balancing algorithm you selected when you add the listener.


   .. figure:: /_static/images/en-us_image_0238395033.png
      :alt: **Figure 2** Layer-7 load balancing

      **Figure 2** Layer-7 load balancing

Backend Servers
---------------

Before you use ELB, you need to create cloud servers, deploy required applications on them, and add the cloud servers to one or more backend server groups. When you create ECSs or BMSs, note the following:

-  Cloud servers must be in the same region as the load balancer.
-  Cloud servers that run the same OS are recommended so that you can manage them more easily.

:original_name: elb_pro_0005.html

.. _elb_pro_0005:

Product Advantages
==================

Advantages of Dedicated Load Balancers
--------------------------------------

-  Robust performance

   Each load balancer has exclusive use of isolated resources, meeting your requirements for handling a massive number of requests. A single load balancer deployed in one AZ can handle up to 20 million concurrent connections.

   If you deploy a load balancer in multiple AZs, its performance such as the number of new connections and the number of concurrent connections will multiply. For example, if you deploy a dedicated load balancer in two AZs, it can handle up to 40 million concurrent connections.

   .. note::

      -  If requests are from the Internet, the load balancer in each AZ you select routes the requests based on source IP addresses. If you deploy a load balancer in two AZs, the requests the load balancers can handle will be doubled.
      -  For requests from a private network:

         -  If clients are in an AZ you have selected when you created the load balancer, requests are distributed by the load balancer in this AZ. If the load balancer becomes unavailable, requests are distributed by the load balancer in another AZ you have selected.

            If the load balancer is available but the connections that the load balancer needs to handle exceed the amount defined in the specifications, service may be interrupted. To address this issue, you need upgrade specifications.

         -  If clients are in an AZ that is not selected when you created the load balancer, requests are distributed by the load balancer in each AZ you select based on source IP addresses.

      -  If clients are in a VPC that is different from where the load balancer works, the load balancer in the AZ where the original VPC subnet resides routes the requests. If the load balancer is unavailable, requests are distributed by the load balancer in another AZ.

-  High availability

   ELB can route traffic uninterruptedly. If your servers in one AZ are unhealthy, it automatically routes traffic to healthy servers in other AZs. ELB provides a comprehensive health check system to ensure that incoming traffic is routed only to healthy backend servers, improving the availability of your applications.

-  Ultra-high security

   ELB supports TLS 1.3 and can route HTTPS requests to backend servers. You can select security policies or customize security policies that fit your security requirements.

-  Multiple protocols

   ELB supports Quick UDP Internet Connection (QUIC), TCP, UDP, HTTP, and HTTPS, so that they can route requests to different types of applications.

-  High flexibility

   ELB can route requests based on their content, such as the request method, header, URL, path, and source IP address. They can also redirect requests to another listener or URL, or return a fixed response to the clients.

-  No limits

   ELB can route requests to both servers on the cloud and on premises, allowing you to leverage cloud resources to handle burst traffic.

-  Ease-of-use

   ELB provides a diverse set of algorithms that allow you to configure different traffic routing policies to meet your requirements while keeping deployments simple.

Advantages of Shared Load Balancers
-----------------------------------

-  High availability

   Shared load balancers can route traffic across AZs, ensuring that your services are uninterrupted. If servers in an AZ are unhealthy, ELB automatically routes traffic to healthy servers in other AZs. Shared load balancers provide a comprehensive health check mechanism to ensure that incoming traffic is routed to only healthy backend servers, improving the availability of your applications.


   .. figure:: /_static/images/en-us_image_0000001794660657.png
      :alt: **Figure 1** High availability

      **Figure 1** High availability

-  Multiple protocols

   ELB supports TCP, UDP, HTTP, and HTTPS protocols to route requests to different types of applications.

-  Ease-of-use

   Shared load balancers provide a diverse set of algorithms that allow you to configure different traffic routing policies to meet your requirements while keeping deployments simple.

-  High reliability

   Shared load balancers are deployed in two AZs by default and can distribute traffic more evenly.

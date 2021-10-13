What Is ELB?
============

Elastic Load Balancing (ELB) automatically distributes incoming traffic across multiple backend servers based on the listening rules you configure. ELB expands the service capabilities of your applications and improves their availability by eliminating single points of failure (SPOFs).

|image1|

ELB Components
--------------

ELB consists of the following components:

-  Load balancer: distributes incoming traffic across backend servers in one or more availability zones (AZs).

-  Listener: uses the protocol and port you specify to check for requests from clients and route the requests to associated backend servers based on the listening rules you define. You can add one or more listeners to a load balancer.

-  Backend server group: routes requests from the load balancer to one or more backend servers. You need to add at least one backend server to a backend server group.

   You can set a weight for each backend server based on their performance.

   You can also configure health checks for a backend server group to check the health of each backend server. When a backend server is unhealthy, the load balancer stops routing new requests to this server.

| **Figure 1** ELB components
| |image2|

Load Balancer Type
------------------

ELB provides the following types of load balancers: classic load balancer, dedicated load balancer, and shared load balancer. Dedicated load balancer and shared load balancer are called elastic load balancers collectively.

-  Dedicated load balancers have exclusive use of underlying resources, so that the performance of a dedicated load balancer is not affected by other load balancers. In addition, there are a wide range of specifications available for selection.

|image3|

Currently, dedicated load balancers are supported only in the **eu-nl** region.

-  Shared load balancers are suitable for web services with heavy traffic. Requests are forwarded based on domain names or URLs, making request routing more flexible. Shared load balancers were previously named enhanced load balancers.

-  Classic load balancers can handle simple, light-traffic web services.\ |image4|

   Classic load balancers can no longer be created on the management console. Use shared load balancers or dedicated load balancers instead.

For details, see `Differences Between Dedicated and Shared Load Balancers <elb_pro_0004.html>`__.

For details, see `Differences Between Shared and Classic Load Balancers <en-us_elb_01_0007.html>`__.

Accessing ELB
-------------

You can use either of the following methods to access ELB:

-  Management console

   Log in to the management console and choose **Network** > **Elastic Load Balancing (ELB)**.

-  APIs

   You can call APIs to access ELB. For details, see the *Elastic Load Balancing API Reference*.

   |image5|

   By default, load balancers created in the **eu-de** region are shared load balancers. APIs for shared load balancers are available only in this region.

   By default, load balancers created in the **eu-nl** region are dedicated load balancers. APIs for dedicated load balancers are available only in this region.

.. |image1| image:: /images/en-us_image_0198606126.png
   :class: vsd

.. |image2| image:: /images/en-us_image_0202311381.png
   :class: vsd

.. |image3| image:: /images/note_3.0-en-us.png
.. |image4| image:: /images/note_3.0-en-us.png
.. |image5| image:: /images/note_3.0-en-us.png

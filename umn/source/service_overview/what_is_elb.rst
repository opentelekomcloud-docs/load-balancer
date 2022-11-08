:original_name: en-us_topic_0015479966.html

.. _en-us_topic_0015479966:

What Is ELB?
============

Elastic Load Balancing (ELB) automatically distributes incoming traffic across multiple backend servers based on the listening rules you configure. ELB expands the service capabilities of your applications and improves their availability by eliminating single points of failure (SPOFs).

|image1|

.. _en-us_topic_0015479966__section031725010213:

ELB Components
--------------

ELB consists of the following components:

-  Load balancer: distributes incoming traffic across backend servers in one or more availability zones (AZs).

-  Listener: uses the protocol and port you specify to check for requests from clients and route the requests to associated backend servers based on the listening rules and forwarding policies you configure. You can add one or more listeners to a load balancer.

-  Backend server group: contains one or more backend servers to receive requests routed by the listener. You need to add at least one backend server to a backend server group.

   You can set a weight for each backend server based on their performance.

   You can also configure health checks for a backend server group to check the health of each backend server. When a backend server is unhealthy, the load balancer stops routing new requests to this server.


.. figure:: /_static/images/en-us_image_0202311381.png
   :alt: **Figure 1** ELB components

   **Figure 1** ELB components

Load Balancer Types
-------------------

ELB provides the following types of load balancers.


.. figure:: /_static/images/en-us_image_0000001252691727.png
   :alt: **Figure 2** Load balancer types

   **Figure 2** Load balancer types

-  Dedicated load balancers have exclusive use of underlying resources, so that the performance of a dedicated load balancer is not affected by other load balancers. In addition, there are a wide range of specifications available for selection.

.. note::

   -  In the eu-de region, you can create both dedicated and shared load balancers, and you can create either type of load balancers on the management console or by calling APIs.
   -  In the eu-nl region, you can only create dedicated load balancers, either on the console or by calling APIs.

-  Shared load balancers are deployed in clusters and share underlying resources, so that the performance of a load balancer is affected by other load balancers. Shared load balancers were previously named enhanced load balancers.

For details, see :ref:`Differences Between Dedicated and Shared Load Balancers <elb_pro_0004>`.

.. _en-us_topic_0015479966__section17818164132517:

Accessing ELB
-------------

You can use either of the following methods to access ELB:

-  Management console

   Log in to the management console and choose **Elastic Load Balancing (ELB)**.

-  APIs

   You can call APIs to access ELB. For details, see the *Elastic Load Balancing API Reference*.

   .. note::

      In the eu-de region, you can create both dedicated and shared load balancers, and you can create either type of load balancers on the management console or by calling APIs.

      In the eu-nl region, you can only create dedicated load balancers, either on the console or by calling APIs.

.. |image1| image:: /_static/images/en-us_image_0198606126.png

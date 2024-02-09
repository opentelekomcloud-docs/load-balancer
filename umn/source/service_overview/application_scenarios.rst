:original_name: elb_pro_0006.html

.. _elb_pro_0006:

Application Scenarios
=====================

Heavy-Traffic Applications
--------------------------

For an application with heavy traffic, such as a large portal or mobile app store, ELB evenly distributes incoming traffic to multiple backend servers, balancing the load while ensuring steady performance.

Sticky sessions ensure that requests from one client are always forwarded to the same backend server for fast processing.


.. figure:: /_static/images/en-us_image_0000001747739756.png
   :alt: **Figure 1** Session stickiness

   **Figure 1** Session stickiness

Applications with Predictable Peaks and Troughs in Traffic
----------------------------------------------------------

For an application that has predictable peaks and troughs in traffic volumes, ELB works with Auto Scaling to add or remove backend servers to keep up with changing demands. An example is flash sales, during which application traffic spikes in a short period. ELB can work with Auto Scaling to run only the required number of backend servers to handle the load of your application.


.. figure:: /_static/images/en-us_image_0000001747380872.png
   :alt: **Figure 2** Flexible scalability

   **Figure 2** Flexible scalability

Zero SPOFs
----------

ELB routinely performs health checks on backend servers to monitor their health. If any backend server is detected unhealthy, ELB will not route requests to this server until it recovers.

This makes ELB a good choice for running services that require high reliability, such as websites and toll collection systems.


.. figure:: /_static/images/en-us_image_0000001794660601.png
   :alt: **Figure 3** Eliminating SPOFs

   **Figure 3** Eliminating SPOFs

Cross-AZ Load Balancing
-----------------------

ELB can distribute traffic across AZs. When an AZ becomes faulty, ELB distributes traffic across backend servers in other AZs.

ELB is ideal for banking, policing, and large application systems that require high availability.


.. figure:: /_static/images/en-us_image_0000001794819713.png
   :alt: **Figure 4** Traffic distribution to servers in one or more AZs

   **Figure 4** Traffic distribution to servers in one or more AZs

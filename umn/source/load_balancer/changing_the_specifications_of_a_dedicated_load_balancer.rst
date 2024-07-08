:original_name: elb_ug_fz_0016.html

.. _elb_ug_fz_0016:

Changing the Specifications of a Dedicated Load Balancer
========================================================

Scenario
--------

This section guides you on how to change the specifications of a dedicated load balancer.

.. note::

   You can only change the specifications of dedicated load balancers.

Changing Specifications
-----------------------

.. table:: **Table 1** Changing the specifications

   +-----------------------------------------+--------------------------+----------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Load Balancing Type                     | Upgrading Specifications | Downgrading Specifications | Description                                                                                                                                                                                                                                            |
   +=========================================+==========================+============================+========================================================================================================================================================================================================================================================+
   | Network load balancing (TCP/UDP)        | Y                        | Y                          | -  The load balancing type cannot be changed after the load balancer is created.                                                                                                                                                                       |
   |                                         |                          |                            |                                                                                                                                                                                                                                                        |
   |                                         |                          |                            | -  If you select the network load balancing (TCP/UDP), you can only create a TCP or UDP listener.                                                                                                                                                      |
   |                                         |                          |                            |                                                                                                                                                                                                                                                        |
   |                                         |                          |                            |    If the specification is downgraded, new connections may not be able to be established.                                                                                                                                                              |
   +-----------------------------------------+--------------------------+----------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
   | Application load balancing (HTTP/HTTPS) | Y                        | Y                          | -  The load balancing type cannot be changed after the load balancer is created.                                                                                                                                                                       |
   |                                         |                          |                            | -  If you select the application load balancing (HTTP/HTTPS), you can only create an HTTP or HTTPS listener. If the specification is downgraded, new connections may not be able to be established and some persistent connections may be interrupted. |
   +-----------------------------------------+--------------------------+----------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. note::

   Downgrading specifications will temporarily affect services.

   -  Network load balancing (TCP/UDP): New connections may fail to establish.
   -  Application load balancing (HTTP/HTTPS): New connections may not be able to be established and some persistent connections may be interrupted.

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer whose specifications you want to modify, click **More** in the **Operation** column, and select **Change Specifications**.
#. Select the new specifications and click **Next**.
#. Confirm the information and click **Submit**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png

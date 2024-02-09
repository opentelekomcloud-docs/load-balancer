:original_name: elb_ug_fz_0009.html

.. _elb_ug_fz_0009:

Binding an IP Address to or Unbinding an IP Address from a Load Balancer
========================================================================

Scenarios
---------

You can bind an IP address to a load balancer or unbind the IP address from a load balancer based on service requirements.

-  An IPv4 EIP or a private IPv4 address can be bound to or unbound from a dedicated load balancer.
-  Only an IPv4 EIP can be bound to or unbound from a shared load balancer.

.. note::

   Note the following before unbinding an IP address:

   -  Load balancers without IPv4 EIPs cannot route requests over the public IPv4 network.

   -  Load balancers without private IPv4 addresses cannot route requests over the private IPv4 network.

   Note the following when you use EIPs of dedicated load balancers (**5_gray**):

   -  In **eu-de**, EIPs of dedicated load balancers (**5_gray**) type cannot be created. The optimal **5_bgp** EIP is recommended.
   -  Existing EIPs of dedicated load balancers (**5_gray**) type can be bound to dedicated or shared load balancers.

      -  You cannot bind EIPs to or unbind them from dedicated load balancers on ELB console.
      -  You can use APIs to bind EIPs to or unbind them from dedicated load balancers. For details, see "Binding an EIP" and "Unbinding an EIP" in "API V3" section in the *Elastic IP API Reference*.
      -  EIPs can be bound to or unbound from shared load balancers using the ELB console or EIP APIs.

   -  Do not add EIPs of the dedicated load balancers (**5_gray**) and EIPs bound to other instances to the same shared bandwidth. Otherwise, the bandwidth limit policy will not take effect.

Binding an IPv4 EIP
-------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer to which you want to bind an IPv4 EIP and click **More** > **Bind IPv4 EIP** in the **Operation** column.
#. In the **Bind IPv4 EIP** dialog box, select the EIP you want to bind to the load balancer.
#. Click **OK**.

Binding a Private IPv4 Address
------------------------------

Only dedicated load balancers support this function.

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer to which you want to bind a private IPv4 address and click **More** > **Bind Private IPv4 Address** in the **Operation** column.
#. In the **Bind Private IPv4 Address** dialog box, select the subnet where the IP address resides and specify the IP address.

   -  By default, the system automatically assigns an IP address. To manually specify an IP address, deselect **Automatically assign IP address** and enter the IP address.
   -  Ensure that the entered IP address belongs to the selected subnet and is not in use.

#. Click **OK**.

Unbinding an IPv4 EIP
---------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer from which you want to unbind the IPv4 EIP and click **More** > **Unbind IPv4 EIP** in the **Operation** column.
#. In the displayed dialog box, confirm the IPv4 EIP that you want to unbind and click **Yes**.

   .. note::

      After the IPv4 EIP is unbound, the load balancer cannot route requests over the Internet.

Unbinding a Private IPv4 Address
--------------------------------

Only dedicated load balancers support this function.

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. On the **Load Balancers** page, locate the load balancer from which you want to unbind the private IPv4 address and click **More** > **Unbind Private IPv4 Address** in the **Operation** column.
#. In the displayed dialog box, confirm the private IPv4 address that you want to unbind and click **Yes**.

   .. note::

      After the private IPv4 address is unbound, the load balancer cannot route requests over the private IPv4 network.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
.. |image5| image:: /_static/images/en-us_image_0000001747739624.png
.. |image6| image:: /_static/images/en-us_image_0000001794660485.png
.. |image7| image:: /_static/images/en-us_image_0000001747739624.png
.. |image8| image:: /_static/images/en-us_image_0000001794660485.png

:original_name: en-us_elb_03_0003.html

.. _en-us_elb_03_0003:

Access Control
==============

Access control allows you to whitelist certain IP addresses to allow them to access a listener.

.. important::

   -  You can add whitelists only to listeners of shared load balancers. Adding whitelists may interrupt services. Once a whitelist is added, only IP addresses in the whitelist can access the listener.
   -  If access control is enabled but no whitelist is added, the listener cannot be accessed.
   -  Whitelists do not conflict with inbound security group rules. Whitelists control access to listeners based on IP addresses or CIDR blocks, whereas inbound security group rules control access to backend servers based on the protocol, ports, and IP addresses.

Adding a Whitelist
------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

4. Locate the load balancer and click its name.
5. Click **Listeners**, locate the listener, and click its name. In the **Basic Information** area, click **Configure** next to **Access Control**.

   .. table:: **Table 1** Parameter description

      +-----------------------+----------------------------------------------------------------------------------------------------------------------------+----------------------------+
      | Parameter             | Description                                                                                                                | Example Value              |
      +=======================+============================================================================================================================+============================+
      | Access Control        | Enabled                                                                                                                    | N/A                        |
      |                       |                                                                                                                            |                            |
      |                       | -  If access control is enabled and no whitelist is set, no IP address can access the listener.                            |                            |
      |                       | -  If access control is enabled and a whitelist is set, only IP addresses in the whitelist can access the listener.        |                            |
      |                       |                                                                                                                            |                            |
      |                       | Disabled                                                                                                                   |                            |
      |                       |                                                                                                                            |                            |
      |                       | -  If access control is disabled, the listener can be accessed from any IP address.                                        |                            |
      +-----------------------+----------------------------------------------------------------------------------------------------------------------------+----------------------------+
      | Whitelist             | Lists the IP addresses that can access the listener.                                                                       | 10.168.2.24,10.168.16.0/24 |
      |                       |                                                                                                                            |                            |
      |                       | .. note::                                                                                                                  |                            |
      |                       |                                                                                                                            |                            |
      |                       |    -  A maximum of 300 IP addresses or IP address ranges are supported. A comma (,) is used to separate every two entries. |                            |
      |                       |    -  The whitelist cannot contain IPv6 addresses.                                                                         |                            |
      +-----------------------+----------------------------------------------------------------------------------------------------------------------------+----------------------------+

6. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png

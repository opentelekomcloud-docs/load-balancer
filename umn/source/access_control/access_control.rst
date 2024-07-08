:original_name: elb_03_0003.html

.. _elb_03_0003:

Access Control
==============

Access control allows you to add a whitelist or blacklist to specify IP addresses that are allowed or denied to access a listener. A whitelist allows specified IP addresses to access the listener, while a blacklist denies access from specified IP addresses.

.. important::

   -  Adding the whitelist or blacklist may cause risks. Once a whitelist is added, only IP addresses in the whitelist can access the listener. After a blacklist is added, IP addresses in the blacklist cannot access the listener.
   -  Whitelists and blacklists do not conflict with inbound security group rules. Whitelists define the IP addresses that are allowed to access the listeners, while blacklists specify IP addresses that are denied to access the listeners. Inbound security group rules control access to backend servers by specifying the protocol, ports, and IP addresses.
   -  Access control does not restrict the **ping** command. You can still ping backend servers from the restricted IP addresses.

      -  To ping the IP address of a shared load balancer, you need to add a listener and associate a backend server to it.
      -  To ping the IP address of a dedicated load balancer, you only need to add a listener to it.

   -  Access control policies only take effect for new connections, but not for connections that have been established. If a whitelist is configured for a listener but IP addresses that are not in the whitelist can access the backend server associated with the listener, one possible reason is that a persistent connection is established between the client and the backend server. To deny IP addresses that are not in the whitelist from accessing the listener, the persistent connection between the client and the backend server needs to be disconnected.

.. _elb_03_0003__section109371640175915:

Configuring Access Control
--------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Click |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

4. Locate the load balancer and click its name.

5. You can configure access control for a listener in either of the following ways:

   -  On the **Listeners** page, locate the listener and click **Configure** in the **Access Control** column.
   -  Click the name of the listener. On the **Basic Information** page, click **Configure** on the right of **Access Control**.

6. In the displayed **Configure Access Control** dialog box, configure parameters as shown in :ref:`Table 1 <elb_03_0003__table159371240125911>`.

   .. _elb_03_0003__table159371240125911:

   .. table:: **Table 1** Parameter description

      +-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Parameter             | Description                                                                                                                                                                                                                    | Example Value         |
      +=======================+================================================================================================================================================================================================================================+=======================+
      | Access Control        | Specifies how access to the listener is controlled. Three options are available:                                                                                                                                               | Blacklist             |
      |                       |                                                                                                                                                                                                                                |                       |
      |                       | -  **All IP addresses**: All IP addresses can access the listener.                                                                                                                                                             |                       |
      |                       | -  **Whitelist**: Only IP addresses in the IP address group can access the listener.                                                                                                                                           |                       |
      |                       | -  **Blacklist**: IP addresses in the IP address group are not allowed to access the listener.                                                                                                                                 |                       |
      +-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | IP Address Group      | Specifies the IP address group associated with a whitelist or blacklist. If there is no IP address group, create one first. For more information, see :ref:`IP Address Group Overview <elb_ug_ip_0000__section1143912015382>`. | ipGroup-b2            |
      +-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+
      | Access Control        | If you have set **Access Control** to **Whitelist** or **Blacklist**, you can enable or disable access control.                                                                                                                | N/A                   |
      |                       |                                                                                                                                                                                                                                |                       |
      |                       | -  Only after you enable access control, the whitelist or blacklist takes effect.                                                                                                                                              |                       |
      |                       | -  If you disable access control, the whitelist or blacklist does not take effect.                                                                                                                                             |                       |
      +-----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------+

7. Click **OK**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png

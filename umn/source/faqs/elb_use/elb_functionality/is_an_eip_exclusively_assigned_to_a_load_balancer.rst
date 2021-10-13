Is an EIP Exclusively Assigned to a Load Balancer?
==================================================

During the lifecycle of a classic load balancer, the EIP is exclusively assigned to it. The EIP is released only when you delete the load balancer.

For each shared load balancer, the bound EIP is not exclusive. However, the EIP can be unbound from the load balancer and bound to other resources. After you unbind the EIP, the load balancer can no longer receive requests over the Internet.

For each dedicated load balancer, the bound EIP is not exclusive. However, the EIP can be unbound from the load balancer and bound to other resources. After you unbind the EIP, the load balancer can no longer receive requests over the Internet.

|image1|

Classic load balancers can no longer be created on the management console. Use shared load balancers or dedicated load balancers instead.

|image2|

You can unbind an EIP from a dedicated load balancer only on the ELB console.

.. |image1| image:: /images/note_3.0-en-us.png
.. |image2| image:: /images/note_3.0-en-us.png

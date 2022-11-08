:original_name: en-us_elb_05_0011.html

.. _en-us_elb_05_0011:

Is an EIP Assigned Exclusively to a Load Balancer?
==================================================

During the lifecycle of a load balancer, whether the assigned EIP is exclusive depends on the type of the load balancer.

-  Dedicated load balancer: The EIP can be unbound from the load balancer. If the EIP is unbound, the load balancer becomes a private network load balancer, and the EIP can be bound to other resources.
-  Shared load balancer: The EIP can be unbound from the load balancer. If the EIP is unbound, the load balancer becomes a private network load balancer, and the EIP can be bound to other resources.

.. note::

   You can unbind an EIP from a load balancer only on the management console.
